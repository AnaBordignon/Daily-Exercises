#include "pascals_triangle.h"

namespace pascals_triangle {
	std::vector<std::vector<int>> generate_rows(int rows) {
		int i{1};
		std::vector<std::vector<int>> result{};

		while (i <= rows) {
			std::vector<int> row{};
			/* first row is always {1} */
			if (i == 1) {
				row.push_back(1);
			}
			/* second row is always {1, 1} */
			else if (i == 2) {
				row.push_back(1);
				row.push_back(1);
			}
			else {
				/* for rows >=3, get previous row, set first and last indexes of current row as 1 and loop through previous row to calculate the rest of the row */
				std::vector<int> prev_row{ result.at(i - 2U) };
				row.push_back(1);
				for (int j{1}; j < i-1; j++) {
					row.push_back(prev_row.at(j-1) + prev_row.at(j));
				}
				row.push_back(1);
			}
			result.push_back(row);
			i++;
		}

		return result;
	}
}  // namespace pascals_triangle
