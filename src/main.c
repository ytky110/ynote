#include "ynote.h"

#include <stdio.h>

YnoteErr process(int argc, char **argv);
YnoteErr process_opt(char *arg, YnoteOpt *opt);
void ynote_perror(YnoteErr error);

int main(int argc, char **argv)
{
    YnoteErr error = {0};

    int i;

    error = process(argc, argv);
    ynote_perror(error);

    return error.status;
}

YnoteErr process(int argc, char **argv)
{
    YnoteErr error = {0};
    YnoteDat data = {YN_DEFAULT_TEMPO, NULL};
    YnoteOpt opt = {0};

    for (i = 1; i < argv; i++)
    {
        if (argv[i][0] == '-')
        {
            error = process_opt(argv[i][0], &opt);
            if (error.status)
                break;
        }
        else
        {
            char *filename = argv[i];
            if (!(fp = fopen(filename, "r")))
            {
                error.status = YN_ERR_FOPEN;
                error.msgarg = filename;
                error.msgarg2 = strerror(errno);
                break;
            }

            error = ynote_parse(fp, &data, opt);
            if (error.status)
                break;

            error = ynote_play(data, opt);
            if (error.status)
                break;
        }
    }

    if (fp)
    {
        fclose(fp);
        fp = NULL;
    }
    free(data.notes);

    return error;
}

YnoteErr process_opt(char *arg, YnoteOpt *opt)
{
    YnoteErr error = {0};
    int i;

    if (arg[1] == '-')
        return process_long_opt(arg, opt);

    for (i = 0; arg[i]; i++)
    {
        switch (arg[i])
        {
        case 'h':
            ynote_help();
            break;
        case 'V':
            ynote_version();
            break;
        default:
            error.status = YN_ERR_UNKNOWN_OPT;
            arg[i+1] = '\0';
            error.msgarg = arg[i];
            break;
        }
    }

    return error;
}

#define YN_PERROR_PRINT(msg) do {                               \
        if (error.msgarg && error.msgarg2) {                    \
            fprintf(stderr, msg, error.msgarg, error.msgarg2);  \
        } else if (error.msgarg) {                              \
            fprintf(stderr, msg, error.msgarg, "");             \
        } else {                                                \
            fprintf(stderr, msg, "", "");                       \
        }                                                       \
    } while (0)

void ynote_perror(YnoteErr error)
{
    switch (error.status)
    {
    case YN_ERR_OK:
        break;

    case YN_ERR_UNKNOWN_OPT:
        YN_PERROR_PRINT(PNAME ": Unknown option: '%s'");
        break;

    case YN_ERR_FOPEN:
        YN_PERROR_PRINT(PNAME ": Failed to open file '%s': %s");
        break;

    default:
        YN_PERROR_PRINT(PNAME ": Unknown error code");
        break;
    }
}
