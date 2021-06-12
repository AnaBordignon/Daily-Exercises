#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H
#include <string>

namespace phone_number {
	class phone_number {
		std::string formatted_number;
	public:
		phone_number(const std::string&);
		std::string number();
		std::string area_code();
		operator std::string() const;
	};
	

}  // namespace phone_number

#endif // PHONE_NUMBER_H