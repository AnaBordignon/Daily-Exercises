#include "nucleotide_count.h"
#include <stdexcept>
#include <algorithm>

namespace nucleotide_count {

	counter::counter(std::string input) {
		for (char& c : input) {
			if (c != 'A' && c != 'C' && c != 'G' && c != 'T') {
				throw std::invalid_argument("Invalid nucleotide.");
			}
		}

		strand.assign(input);
	}

	std::map<char, int> counter::nucleotide_counts() const {

		std::map<char, int> count_nuc{};
		int sum{};
		
		count_nuc.insert({'A', std::count(strand.begin(), strand.end(), 'A')});
		sum += count_nuc['A'];
		
		count_nuc.insert({'C', std::count(strand.begin(), strand.end(), 'C')});
		sum += count_nuc['C'];
		
		count_nuc.insert({'G', std::count(strand.begin(), strand.end(), 'G')});
		sum += count_nuc['G'];
		
		count_nuc.insert({'T', std::count(strand.begin(), strand.end(), 'T')});
		sum += count_nuc['T'];
	

		if (sum < strand.size()) {
			throw std::invalid_argument("Invalid nucleotide.");
		}

		
		return count_nuc;
	}

	int counter::count(char c) const {
		if (c != 'A' && c != 'C' && c != 'G' && c != 'T') {
			throw std::invalid_argument("Invalid nucleotide.");
		}
		return std::count(strand.begin(), strand.end(), c);
	}

}  // namespace nucleotide_count
