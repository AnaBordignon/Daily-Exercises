#include "reverse_string.h"

namespace reverse_string {

	std::string reverse_string(std::string input) {

		for (int i{}; i < input.length() / 2; i++) {
			std::swap(input[i], input[input.length() - 1 - i]);
		}
		return input;
	}
}  // namespace reverse_string
