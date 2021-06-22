#include "roman_numerals.h"
#include <vector>

namespace roman_numerals {
	/* converts decimal to roman numeral */
	std::string convert(int input) {
		std::vector<std::pair<int, std::string>> numbers{ {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"} };
		int remain{ input };
		std::string result{};

		while (remain > 0) {
			/* look for the highest value from numbers that is equal or lower than the input (x), add the corresponding roman alg to the result and repeat the process with input - x */
			for (auto itr = numbers.begin(); itr != numbers.end(); itr++) {
				if (itr->first <= remain) {
					remain -= itr->first;
					result.append(itr->second);
					break;
				}
			}
		}

		return result;
	}
}  // namespace roman_numerals
