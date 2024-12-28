#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

#include "termin.h"

// Stores the terminal flags as they were before termin_unbuffered.
static tcflag_t termin_echo;

// The termios flags that will be manipulated.
#define TERMIN_FLAGS (ECHO | ECHONL | ICANON)

void termin_reset() {
	struct termios term;
	tcgetattr(0, &term);

	term.c_lflag |= termin_echo;
	tcsetattr(0, TCSAFLUSH, &term);
}

void termin_unbuffered() {
	// have stdin unbuffered at the stdio level.
	setvbuf(stdin, 0, _IONBF, 0);

	// Store the original terminal settings associated with stdin.
	struct termios term;
	tcgetattr(0, &term);
	termin_echo = term.c_lflag & TERMIN_FLAGS;

	// Register exit hanlers.
	atexit(termin_reset);
	at_quick_exit(termin_reset);

	// Change the terminal settings to raw mode.
	term.c_lflag &= ~TERMIN_FLAGS;
	tcsetattr(0, TCSAFLUSH, &term);
}
