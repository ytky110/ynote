#ifndef YNOTE_H_
#define YNOTE_H_

#include <stddef.h>
#include <stdint.h>

#define PNAME "ynote"

#define YN_A (440)
#define YN_DEFAULT_TEMPO (120)

#define YN_NOTEBUF_SIZE ((size_t) 16)
#define STRBUF_SIZE ((size_t) 256)

#include "types.h"
#include "util.h"

int ynote_help(void);
int ynote_version(void);

YnoteErr ynote_parse(FILE *fp, YnoteDat *data);
YnoteErr ynote_play(YnoteDat data);

#endif /* YNOTE_H_ */
