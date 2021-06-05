#include "bob.h"
#include <cctype>
#include <algorithm>
#include <regex>

namespace bob {

	/* true if the char is not a letter in the alphabet */
	bool not_alpha(char c) { return !(isalpha(c)); }

	/* true if string has only uppercase letters, punctuation and digits. If string has no letters, it is false. */
	bool is_uppercase_string(std::string input) {
		int i{};


		input.erase(std::remove_if(input.begin(), input.end(), not_alpha), input.end());
		if (input.length() == 0) {
			return false;
		}

		while (input[i] != '\0') {
			if (std::islower(input[i])) {
				return false;
			}
			i++;
		}
		return true;
	}

	std::string hey(std::string input) {
		
		/* Remove spaces */
		input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());

		if (input.length() == 0) {
			/* approach Bob without saying anything */
			return "Fine. Be that way!";
		}
		else {
			if (input[(input.length() - 1)] == '?') {
				/* it is a question */
				if (is_uppercase_string(input)) /* yelling */
					return "Calm down, I know what I'm doing!";
				else /* normal tone */
					return "Sure.";
			}
			else {
				/* it is not a question */
				if (is_uppercase_string(input)) /* yelling */
					return "Whoa, chill out!";
				else /* normal tone */
					return "Whatever.";
			}
		}
	}

}  // namespace bob
