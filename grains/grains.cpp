#include "grains.h"

namespace grains {

	/* shift 'square position' bits to the left: N*K2 => 1 * pos^2 */
	unsigned long long square(int pos) {
		return 1ULL << (pos-1);
	}

	/* accumulates 64 times the result of the squares */
	unsigned long long total() {
		unsigned long long tot{};
		for (int i{ 64 }; i > 0; i--) {
			tot += square(i);

		}
		return tot;
	}
}  // namespace grains
