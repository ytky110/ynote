#ifndef YNOTE_
#define YNOTE_

#include <stddef.h>
#include <stdint.h>

typedef uint32_t uint;

#define PNAME "ynote"

#define YN_A (440)
#define YN_DEFAULT_TEMPO (120)

#define STRBUF_SIZE ((size_t) 256)

enum YnoteErrCode
{
    YN_ERR_OK = 0,

    /* need msgarg */
    YN_ERR_UNKNOWN_OPT,

    /* need msgarg2 */
    YN_ERR_FOPEN,
};

typedef struct YnoteErr_
{
    enum YnoteErrCode status;
    char *msgarg;
    char *msgarg2;
} YnoteErr;

typedef struct YnoteOpt_
{
    int _dummy;
} YnoteOpt;

enum YnoteNoteID
{
    YN_NOTE_C,
    YN_NOTE_CIS,
    YN_NOTE_D,
    YN_NOTE_DIS,
    YN_NOTE_E,
    YN_NOTE_F,
    YN_NOTE_FIS,
    YN_NOTE_G,
    YN_NOTE_GIS,
    YN_NOTE_A,
    YN_NOTE_AIS,
    YN_NOTE_B,
};

typedef struct YnoteNote_
{
    int octave;
    int duration;
    enum YnoteNoteID id;
} YnoteNote;

typedef struct YnoteDat_
{
    uint tempo;
    YnoteNote *notes;
} YnoteDat;

int ynote_help(void);
int ynote_version(void);

YnoteErr ynote_parse(FILE *fp, YnoteDat *data);
YnoteErr ynote_play(YnoteDat data);

#endif /* YNOTE_ */
