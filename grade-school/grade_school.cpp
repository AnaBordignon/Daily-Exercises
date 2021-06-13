#include "grade_school.h"
#include <algorithm>

namespace grade_school {

	/* Add new student to a grade */
	void school::add(std::string name, int grade) {
		std::map<int, std::vector<std::string>>::iterator itr;
		bool found_grade{ false };

		for (itr = list_students.begin(); itr != list_students.end(); itr++) {
			/* if grade already exists, add student and sorts alphabetically */
			if (itr->first == grade) {
				itr->second.push_back(name);
				std::sort(list_students.find(grade)->second.begin(), list_students.find(grade)->second.end());
				found_grade = true;
			}
		}
		/* if grade doesn't exist, creates and adds new student */
		if (!found_grade) {
			std::vector<std::string> new_grade{ name };
			list_students.insert(std::pair<int, std::vector<std::string> >(grade, new_grade));
		}
	}

	/* return all students in a grade or empty vector if grade doesnt exist */
	std::vector<std::string> school::grade(int grade_no) const{
		auto grade_item = list_students.find(grade_no);
		if (grade_item != list_students.end()) {
			return grade_item->second;
		}
		return std::vector<std::string>{};
	}

	/* returns all students in school */
	std::map<int, std::vector<std::string>> school::roster() const {
		return list_students;
	}




}  // namespace grade_school
