#include "phone_number.h"
#include <regex>


namespace phone_number {

	/* Remove all non-numerical characters from the number and the international country code (when present) */
	phone_number::phone_number(const std::string& phone) {
		std::regex not_number("\\D");
		formatted_number = std::regex_replace(phone, not_number, "");

		/* Number should be (NXX)-NXX-XXXX, where N in (2,9) and X in (0,9) */
		std::regex format("^[1]?[2-9]{1}[0-9]{2}[2-9]{1}[0-9]{2}[0-9]{4}");

		if (std::regex_match(formatted_number, format)) {
			if (formatted_number.front() == '1') {
				formatted_number.erase(formatted_number.begin());
			}
		}
		else {
			throw std::domain_error(" Invalid phone number.");
		}
	}

	/* Returns the plain number */
	std::string phone_number::number() {
		return formatted_number;
	}

	/* Returns only area code (first 3 numbers */
	std::string phone_number::area_code() {
		return formatted_number.substr(0, 3);
	}

	/* Overloads operator to return "(NXX) NXX-XXXX" */
	phone_number::operator std::string() const{
		
		return std::string{ "(" } + formatted_number.substr(0, 3) + ") " + formatted_number.substr(3, 3) + "-" + formatted_number.substr(6, 4);
	}

}  // namespace phone_number
