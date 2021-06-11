#include "food_chain.h"
#include <vector>
#include <sstream>
#include <stdexcept>

namespace food_chain {

	std::string verse(int times) {

		std::stringstream verse;
		std::vector<std::pair<std::string, std::string>> animals{ 
			{"fly", "I don't know why she swallowed the fly. Perhaps she'll die.\n"}, 
			{"spider", "It wriggled and jiggled and tickled inside her.\n"}, 
			{"bird", "How absurd to swallow a bird!\n"}, 
			{"cat", "Imagine that, to swallow a cat!\n"}, 
			{"dog", "What a hog, to swallow a dog!\n"}, 
			{"goat", "Just opened her throat and swallowed a goat!\n"}, 
			{"cow", "I don't know how she swallowed a cow!\n"} };

		std::string spider_variation = " that wriggled and jiggled and tickled inside her.\n";
		std::string main_str = "I know an old lady who swallowed a ";
		
		if (times < 1 || times > 8) {
			throw std::out_of_range("Verse must be in [1, 8]");
		}

		if (times == 8) {
			verse.str(std::string("I know an old lady who swallowed a horse.\n"
				"She's dead, of course!\n"));
		}
		else {
			verse << main_str << animals[times - 1].first << ".\n";
			(times != 1) ? verse << animals[times - 1].second : verse << "";

			for (int i{ times }; i > 1; i--) {
				verse << "She swallowed the " <<
					animals[i - 1].first <<
					" to catch the " <<
					animals[i - 2].first << 
					(animals[i - 2].first == "spider"  ? spider_variation : ".\n");
			}

			verse << animals[0].second;
		}

		return verse.str();
	}

	std::string verses(int first, int last) {

		std::stringstream verses;

		for (int i{ first }; i <= last; i++) {
			verses << verse(i) << "\n";
		}

		return verses.str();
	}

	std::string sing() {

		std::stringstream song;

		for (int i{ 1 }; i <= 8; i++) {
			song << verse(i) << "\n";
		}

		return song.str();
	}

}  // namespace food_chain
