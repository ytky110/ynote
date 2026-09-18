#ifndef YNOTE_TYPES_H_
#define YNOTE_TYPES_H_

typedef uint32_t uint;

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
    YN_NOTE_X = 0,
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
    uint transpose;
    YnoteNote *notes;
} YnoteDat;

enum YnoteCmdID
{
    YN_CMD_TEMPO,
    YN_CMD_TRANSPOSE,
    YN_CMD_TRANSPOSE_WHOLE,
};

typedef struct YnoteCmd_
{
    enum YnoteCmdID id;
    void *arg;
} YnoteCmd;

#endif /* YNOTE_TYPES_H_ */
