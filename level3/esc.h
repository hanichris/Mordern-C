#ifndef ESC_H
#define ESC_H 1

#include <stdio.h>

#define ESC_CSI     "\x1b["

#define ESC_SAVE    ESC_CSI "s"
#define ESC_RESTORE ESC_CSI "u"
#define ESC_HOME    ESC_CSI "H"
#define ESC_CLRSCR  ESC_CSI "1J"
#define ESC_CLEAR   ESC_CSI "2K"
#define ESC_UP      ESC_CSI "A"
#define ESC_DOWN    ESC_CSI "B"
#define ESC_FRWD    ESC_CSI "C"
#define ESC_BKWD    ESC_CSI "D"
#define ESC_END     ESC_CSI "F"
#define ESC_INSERT  ESC_CSI "2~"
#define ESC_DELETE  ESC_CSI "3~"
#define ESC_PGUP    ESC_CSI "5~"
#define ESC_PGDOWN  ESC_CSI "6~"

#define ESC_HIDE    ESC_CSI "?25l"
#define ESC_SHOW    ESC_CSI "?25h"

#define ESC_NORMAL  ESC_CSI "0m"
#define ESC_BOLD    ESC_CSI "1m"
#define ESC_UNDERL  ESC_CSI "4m"
#define ESC_BLINK   ESC_CSI "5m"
#define ESC_INVERS  ESC_CSI "7m"
#define ESC_FRAMED  ESC_CSI "51m"
#define ESC_CIRCLED ESC_CSI "52m"
#define ESC_OVERL   ESC_CSI "53m"

/**
 * relative cursor movement.
 **/
void esc_move(FILE* f, int vert, int hori);

/**
 * absolute cursor movement
 **/
void esc_goto(FILE* f, unsigned vert, unsigned hori);

#endif
