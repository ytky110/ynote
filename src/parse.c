#include "ynote.h"

YnoteErr ynote_parse(FILE *fp, YnoteDat *data)
{
    YnoteErr error = {0};

    int c;

    while (1)
    {
        c = fgetc(fp);

        switch (c)
        {
        case '!':
            YnoteCmd cmd;
            error = ynote_parse_cmdline(fp, &cmd);
            if (error.status) goto error;
            error = ynote_execute_cmd(cmd, data);
            if (error.status) goto error;
            break;
        case '#':
            error = ynote_parse_comment(fp);
            if (error.status) goto error;
            break;
        default:
            error = ynote_parse_note(fp, data);
            if (error.status) goto error;
            break;
        }
    }

    error:
        ;

    return error;
}

YnoteErr ynote_parse_note(FILE *fp, YnoteDat *data)
{
    YnoteErr error;
    YnoteDat result = *data;

    char notebuf[YN_NOTEBUF_SIZE] = {0};

    error = ynote_read_note(fp, YN_NOTEBUF_SIZE, notebuf);
    if (error.status) goto error;
}

YnoteErr ynote_read_note(FILE *fp, size_t bufsize, char *notebuf)
{
    int c, i;

    for (i = 0; i < bufsize; i++)
    {
        c = fgetc(fp);
        if (ynote_is_whitespace(c))
        {
            break;
        }
    }
}

YnoteErr ynote_parse_cmdline(FILE *fp, YnoteCmd *cmd)
{
}

YnoteErr ynote_execute_cmd(YnoteCmd cmd, YnoteDat *data)
{
}
