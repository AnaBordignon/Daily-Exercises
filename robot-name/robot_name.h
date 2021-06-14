#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H
#include <string>
#include <vector>

namespace robot_name {

	class robot {
		std::string _name{"     "};
		static std::vector<std::string> list_robots;

		std::string generate_name();
	public:
		robot();
		std::string name() const;
		void reset();
	};
}  // namespace robot_name

#endif // ROBOT_NAME_H