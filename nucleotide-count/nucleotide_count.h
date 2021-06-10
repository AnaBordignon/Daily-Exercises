#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H
#include <map>
#include <string>

namespace nucleotide_count {
	class counter {
	public:
		std::string strand;

		counter(std::string input);

		std::map<char, int> nucleotide_counts() const;
		int count(char c) const;
	};
}  // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H