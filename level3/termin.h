#ifndef TERMIN_H
#define TERMIN_H 1

/**
 * Set a terminal on stdin to raw mode.
 * It uses termios.h underneath.
 *
 * The terminal is reset by help of termin_rest to its original state on `quick_exit` or `exit`.
 */
void termin_unbuffered(void);

/**
 * Reset the terminal to its orginal state.
 */
void termin_reset(void);

#endif
