#if !defined(ANAGRAM_H)
#define ANAGRAM_H

#include <vector>
#include <string>

namespace anagram {
	class anagram {
	private:
		std::string word;

	public:
		anagram(std::string);
		std::vector<std::string> matches(std::vector<std::string>);
	};
}  // namespace anagram

#endif // ANAGRAM_H