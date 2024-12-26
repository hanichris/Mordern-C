#include <stdalign.h>
#include <stddef.h>
#include <stdio.h>

struct tib {
	int tib_sec;
	int tib_min;
	int tib_hr;
	int tib_day;
	int tib_mon;
	signed tib_year;
	int tib_wday;
	int tib_yday;
	bool tib_isdat;
};

struct compressed_tib {
	unsigned _BitInt(6) tib_sec : 6;
	unsigned _BitInt(6) tib_min : 6;
	unsigned _BitInt(5) tib_hr  : 5;
	unsigned _BitInt(5) tib_day : 5;
	unsigned _BitInt(4) tib_mon : 4;
	unsigned _BitInt(3) tib_wday : 3;
	unsigned _BitInt(9) tib_yday : 9;
	bool                tib_isdat : 1;
	unsigned tib_year;
};


int main(void) {
	printf("Structure size: %zu\n", sizeof(struct tib));
	printf("Compressed structure size: %zu\n", sizeof(struct compressed_tib));
	
	struct compressed_tib today = {
		.tib_sec = 47,
		.tib_min = 8,
		.tib_hr = 5,
		.tib_day = 26,
		.tib_mon = 11,
		.tib_year = 124,
		.tib_wday = 4,
		.tib_yday = 361,
		.tib_isdat = 0,
	};

	printf(
		"Day: %.2u/%.2u/%.4u\n",
		(unsigned)today.tib_day,
		(unsigned)(today.tib_mon + 1wbu),
		1900 + today.tib_year);

	printf(
	"Time: %.2u:%.2u:%.2u %s\n",
	(unsigned)today.tib_hr,
	(unsigned)today.tib_min,
	(unsigned)today.tib_sec,
	today.tib_hr > 12wbu ? "PM" : "AM");

	return 0;
}
