#include "robot_name.h"
#include <stdlib.h>
#include <time.h>
#include <stdexcept>

namespace robot_name {
	
	std::vector<std::string> robot::list_robots;

	/* Initialize a robot with a name */
	robot::robot() {
		std::string rand_name{ "     " };
        
		rand_name = generate_name();

		if (rand_name != "     ") {
			_name = rand_name;
			list_robots.push_back(rand_name);
		}
		else {
			throw std::out_of_range("A new name could not be generated.");
		}
	}

	/* Generates a random name in the format AA000 */
	std::string robot::generate_name() {
		std::string rand_name{ "     " };
		bool valid_name{ false };
		int counter{ 0 };
		std::vector<std::string>::iterator itr;

		srand(time(0));

		/* try while couldn't generate a unique name, but stops trying at counter */
		while (!valid_name && counter < 1000) {
			rand_name[0] = rand() % 25 + 65;
			rand_name[1] = rand() % 25 + 65;
			rand_name[2] = rand() % 9 + 48;
			rand_name[3] = rand() % 9 + 48;
			rand_name[4] = rand() % 9 + 48;

			/* Check if it is not a duplicate name */
			itr = std::find(list_robots.begin(), list_robots.end(), rand_name);
			if (itr == list_robots.end() || list_robots.empty())
			{
				valid_name = true;
			}
			counter++;
		}
		if (counter >= 1000) {
			rand_name = "     ";
		}

		return rand_name;
	}

	/* returns robot name */
	std::string robot::name() const {
		return _name;
	}

	/* Resets robot name and attributes a new one. Old name is kept in the list of used robot names */
	void robot::reset() {
		std::string rand_name{ "     " };

		rand_name = generate_name();
		if (rand_name != "     ") {
			_name = rand_name;
			list_robots.push_back(rand_name);
		}
		else {
			throw std::out_of_range("A new name could not be generated.");
		}
	}

}  // namespace robot_name
