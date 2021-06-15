#include "sum_of_multiples.h"

namespace sum_of_multiples {
	int to(std::vector<int> multiples, int limit) {
        int result{ 0 };
        for (int i{ 1 }; i < limit; i++) {
            for (int m : multiples) {
                if (i % m == 0) {
                    result += i;
                    break;
                }
            }
        }

        return result;
	}
}  // namespace sum_of_multiples
