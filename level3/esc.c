#include "esc.h"

void esc_move(FILE *f, int vert, int hori) {
	if (vert > 0)
		fprintf(f, ESC_CSI "%dB", vert);
	else if (vert < 0)
		fprintf(f, ESC_CSI "%dA", vert);

	if (hori > 0)
		fprintf(f, ESC_CSI "%dC", hori);
	else if (hori < 0)
		fprintf(f, ESC_CSI "%dD", hori);
}

void esc_goto(FILE *f, unsigned int vert, unsigned int hori) {
	fprintf(f, ESC_CSI "%u;%uH", vert, hori);
}
