#include "anagram.h"
#include <algorithm>

namespace anagram {
	/* constructor */
	anagram::anagram(std::string input) {
		word = input;
	}

	/* note to future self: reimplement sort already with tolower */
	std::vector<std::string> anagram::matches(std::vector<std::string> candidates) {
		
		std::string sorted_candidate{};
		std::string sorted_word{};
		bool anagram{true};
		std::vector<std::string> anagrams{};

		/* Input word to lowercase */
		std::transform(word.begin(), word.end(), word.begin(),
			[](unsigned char c) { return std::tolower(c); });

		/* Sort letters in input word */
		sorted_word = word;
		std::sort(sorted_word.begin(), sorted_word.end());

		for (auto& candidate : candidates) {

			/* if both words have the same length, they may be anagrams, otherwise not */
			if (candidate.length() == word.length()) {

				/* Copy candidate to keep word unchanged and sort the candidate to compare */
				
				sorted_candidate = candidate;
				std::transform(sorted_candidate.begin(), sorted_candidate.end(), sorted_candidate.begin(),
					[](unsigned char c) { return std::tolower(c); });
				
				/* Check if words are not the same */
				if (word != sorted_candidate) {

					std::sort(sorted_candidate.begin(), sorted_candidate.end());

					for (int i{}; i < sorted_candidate.length(); i++) {
						/* Compare each letter between initial word and candidate */
						if (sorted_candidate[i] != sorted_word[i]) {
							anagram = false;
							break;
						}
					}

					if (anagram) {
						anagrams.push_back(candidate);
					}
				}
			}
			anagram = true;
				
		}

		return anagrams;
	}

}  // namespace anagram
