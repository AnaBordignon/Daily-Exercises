#include "raindrops.h"

namespace raindrops {

	std::string convert(int input) {
		std::string result{};
		if (input % 3 == 0) {
			result.append("Pling");
		}
		if (input % 5 == 0) {
			result.append("Plang");
		}
		if (input % 7 == 0) {
			result.append("Plong");
		}

		if (result.length() == 0) {
			result.append(std::to_string(input));
		}

		return result;
	}
}  // namespace raindrops
