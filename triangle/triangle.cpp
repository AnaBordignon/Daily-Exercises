#include "triangle.h"
#include <stdexcept>

namespace triangle {
	flavor kind(double a, double b, double c) {
		
		/* test for invalid cases (length has to be a positive value and comply to inequality of triangles */
		if (a <= 0 || b <= 0 || c <= 0) {
			throw std::domain_error("Sides of a triangle shall be bigger than 0.");
		}
		else if ((a + b < c) || (a + c < b) || (c + b < a)) {
			throw std::domain_error("Shape does not comply to inequality pf triangles.");
		}

		if (a == b && b == c) {
			return flavor::equilateral;
		}
		else if (a == b || b == c || a == c) {
			return flavor::isosceles;
		}
		else {
			return flavor::scalene;
		}
	}
}  // namespace triangle
