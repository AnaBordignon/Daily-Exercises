#include "trinary.h"

namespace trinary {
	/* converts a value in base 3 to decimal */
	int to_decimal(std::string input) {
		int result{};
		int base{ 1 };
		int tri_length = input.length() - 1;

		/* conversion: x4 * 2^3 + x3 * 2^2 + x2 * 2^1 + x1 * 2^0 */
		for (int i{ tri_length }; i >= 0; i--) {
			if (input[i] == '2' || input[i] == '1' || input[i] == '0') {
				result += ((int)(input[i] - 48) * base);
				base *= 3;
			}
			/* if input is not valid, returns 0 */
			else {
				result = 0;
				break;
			}
		}
		return result;
	}
}  // namespace trinary
