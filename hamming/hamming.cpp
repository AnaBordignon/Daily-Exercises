#include "hamming.h"
#include <stdexcept>

namespace hamming {

	unsigned int compute(std::string input1, std::string input2) {

		unsigned int count{};

		if (input1.length() != input2.length()) {
			throw std::domain_error("Both inputs shall have the same length.");
		}

		for (int i{}; i < input1.length(); i++) {
			if (input1[i] != input2[i]) {
				count++;
			}
		}
		return count;
	}
}  // namespace hamming
