#if !defined(MEETUP_H)
#define MEETUP_H
#include <boost/date_time/gregorian/gregorian.hpp>

namespace meetup {

	using boost::date_time::months_of_year;
	using boost::gregorian::date;

	using nth_day_week = boost::gregorian::nth_day_of_the_week_in_month;
	using boost::gregorian::nth_kday_of_month;

	using boost::gregorian::greg_weekday;
	using boost::gregorian::Monday;
	using boost::gregorian::Tuesday;
	using boost::gregorian::Wednesday;
	using boost::gregorian::Thursday;
	using boost::gregorian::Friday;
	using boost::gregorian::Saturday;
	using boost::gregorian::Sunday;

	class scheduler {
		months_of_year _month;
		int _year;

		date findday(int from, int to, greg_weekday day) const;

	public:
		scheduler(months_of_year month, int year);

		date monteenth() const;
		date tuesteenth() const;
		date wednesteenth() const;
		date thursteenth() const;
		date friteenth() const;
		date saturteenth() const;
		date sunteenth() const;

		date first_monday() const;
		date first_tuesday() const;
		date first_wednesday() const;
		date first_thursday() const;
		date first_friday() const;
		date first_saturday() const;
		date first_sunday() const;
	
		date second_monday() const;
		date second_tuesday() const;
		date second_wednesday() const;
		date second_thursday() const;
		date second_friday() const;
		date second_saturday() const;
		date second_sunday() const;

		date third_monday() const;
		date third_tuesday() const;
		date third_wednesday() const;
		date third_thursday() const;
		date third_friday() const;
		date third_saturday() const;
		date third_sunday() const;

		date fourth_monday() const;
		date fourth_tuesday() const;
		date fourth_wednesday() const;
		date fourth_thursday() const;
		date fourth_friday() const;
		date fourth_saturday() const;
		date fourth_sunday() const;

		date last_monday() const;
		date last_tuesday() const;
		date last_wednesday() const;
		date last_thursday() const;
		date last_friday() const;
		date last_saturday() const;
		date last_sunday() const;
	};
}  // namespace meetup

#endif // MEETUP_H