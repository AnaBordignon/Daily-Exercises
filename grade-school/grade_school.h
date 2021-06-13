#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H
#include <string>
#include <map>
#include <vector>

namespace grade_school {
	class school {
		std::map<int, std::vector<std::string>> list_students{};

	public:
		void add(std::string name, int grade);
		std::vector<std::string> grade(int grade_no) const;
		std::map<int, std::vector<std::string>> roster() const;
	};
}  // namespace grade_school

#endif // GRADE_SCHOOL_H