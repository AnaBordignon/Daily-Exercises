#include "isogram.h"

namespace isogram {

	/* Unary function to evaluate if char is space or hyphen. */
	bool IsHyphenOrSpace(char c) { return ((c == '-') || (c == ' ')); }

	bool is_isogram(std::string input) {

		/* Remove spaces and hyphens */
		input.erase(std::remove_if(input.begin(), input.end(), IsHyphenOrSpace), input.end());
		/* Convert string to lower case */
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);

		for (int i{}; i < input.length(); i++) {
			/* Look for char in the rest of the string */
			size_t found = input.find(input[i], (size_t)i + 1);
			if (found != std::string::npos) {
				return false;
			}
		}
		return true;
	}
}  // namespace isogram
