#include "difference_of_squares.h"
#include <math.h>

namespace difference_of_squares {

	int square_of_sum(int input) {

		int sum = input;

		for (int i = 1; i < input; i++)
			sum += i;

		return pow(sum, 2);
	}

	int sum_of_squares(int input) {
		int sum = pow(input, 2);

		for (int i = 1; i < input; i++)
			sum += pow(i, 2);

		return sum;
	}

	int difference(int input) {

		return (square_of_sum(input) - sum_of_squares(input));
	}
}  // namespace difference_of_squares
