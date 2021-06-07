#include "etl.h"
#include <string>



namespace etl {

	std::map<char, int> transform(std::map<int, std::vector<char>> old) {
		
		std::map<char, int> new_scores;
        std::map<int, std::vector<char>>::iterator itr;

        for (itr = old.begin(); itr != old.end(); ++itr) {
			for (auto i = itr->second.begin(); i != itr->second.end(); ++i) {
				new_scores.insert(std::pair<char, int>(tolower(*i), itr->first));
			} 
        }

		return new_scores;
	}
}  // namespace etl
