#include "binary.h"

namespace binary {
	int convert(std::string binary) {
		int result{};
		int base{ 1 };
		int bin_length = binary.length() - 1;

		/* conversion: x4 * 2^3 + x3 * 2^2 + x2 * 2^1 + x1 * 2^0 */
		for (int i{bin_length}; i >= 0; i--) {
			if (binary[i] == '1' || binary[i] == '0') {
				result += ((int)(binary[i] - 48) * base);
				base *= 2;
			}
			/* if input is not valid, returns 0 */
			else {
				result = 0;
				break;
			}
		}
		return result;
	}
}  // namespace binary
