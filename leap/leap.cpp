#include "leap.h"

namespace leap {

	/* Calculates if a given year is a leap year. */
	bool is_leap_year(int year) {
		if (((year % 4 == 0) && !(year % 100 == 0)) || ((year % 4 == 0) && (year % 400 == 0))) {
			return true;
		}
		return false;
	}
}  // namespace leap
