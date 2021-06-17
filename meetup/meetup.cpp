#include "meetup.h"


namespace meetup {

	scheduler::scheduler(months_of_year month, int year) {
		_month = month;
		_year = year;
	}

	date scheduler::findday(int from, int to, greg_weekday day) const {
		boost::gregorian::day_iterator d(date(_year, _month, to));

		for (; d->day() >= from; --d) {
			if (d->day_of_week() == day) {
				return *d;
			}
		}
	}


	date scheduler::monteenth() const { 
		return findday(13, 19, Monday); 
	}
	date scheduler::tuesteenth() const {
		return findday(13, 19, Tuesday);
	}
	date scheduler::wednesteenth() const {
		return findday(13, 19, Wednesday);
	}
	date scheduler::thursteenth() const {
		return findday(13, 19, Thursday);
	}
	date scheduler::friteenth() const {
		return findday(13, 19, Friday);
	}
	date scheduler::saturteenth() const {
		return findday(13, 19, Saturday);
	}
	date scheduler::sunteenth() const {
		return findday(13, 19, Sunday);
	}
	
	date scheduler::first_monday() const { 
		return findday(1, 7, Monday); 
	}
	date scheduler::first_tuesday() const { 
		return findday(1, 7, Tuesday); 
	}
	date scheduler::first_wednesday() const {
		return findday(1, 7, Wednesday); 
	}
	date scheduler::first_thursday() const {
		return findday(1, 7, Thursday); 
	}
	date scheduler::first_friday() const {
		return findday(1, 7, Friday); 
	}
	date scheduler::first_saturday() const {
		return findday(1, 7, Saturday); 
	}
	date scheduler::first_sunday() const {
		return findday(1, 7, Sunday); 
	}

	date scheduler::second_monday() const { 
		return findday(8, 14, Monday);
	}
	date scheduler::second_tuesday() const { 
		return findday(8, 14, Tuesday); 
	}
	date scheduler::second_wednesday() const { 
		return findday(8, 14, Wednesday); 
	}
	date scheduler::second_thursday() const { 
		return findday(8, 14, Thursday); 
	}
	date scheduler::second_friday() const { 
		return findday(8, 14, Friday); 
	}
	date scheduler::second_saturday() const { 
		return findday(8, 14, Saturday); 
	}
	date scheduler::second_sunday() const { 
		return findday(8, 14, Sunday); 
	}

	date scheduler::third_monday() const { 
		return findday(15, 21, Monday); 
	}
	date scheduler::third_tuesday() const { 
		return findday(15, 21, Tuesday); 
	}
	date scheduler::third_wednesday() const { 
		return findday(15, 21, Wednesday);
	}
	date scheduler::third_thursday() const { 
		return findday(15, 21, Thursday); 
	}
	date scheduler::third_friday() const { 
		return findday(15, 21, Friday); 
	}
	date scheduler::third_saturday() const { 
		return findday(15, 21, Saturday); 
	}
	date scheduler::third_sunday() const { 
		return findday(15, 21, Sunday); 
	}

	date scheduler::fourth_monday() const { 
		return findday(22, 28, Monday); 
	}
	date scheduler::fourth_tuesday() const { 
		return findday(22, 28, Tuesday); 
	}
	date scheduler::fourth_wednesday() const { 
		return findday(22, 28, Wednesday); 
	}
	date scheduler::fourth_thursday() const { 
		return findday(22, 28, Thursday); 
	}
	date scheduler::fourth_friday() const { 
		return findday(22, 28, Friday); 
	}
	date scheduler::fourth_saturday() const { 
		return findday(22, 28, Saturday); 
	}
	date scheduler::fourth_sunday() const { 
		return findday(22, 28, Sunday); 
	}
	
	date scheduler::last_monday() const { 
		date d(_year, _month, 1);
		return findday(1, d.end_of_month().day(), Monday);
	}
	date scheduler::last_tuesday() const { 
		date d(_year, _month, 1);
		return findday(1, d.end_of_month().day(), Tuesday);
	}
	date scheduler::last_wednesday() const { 
		date d(_year, _month, 1);
		return findday(1, d.end_of_month().day(), Wednesday);
	}
	date scheduler::last_thursday() const { 
		date d(_year, _month, 1);
		return findday(1, d.end_of_month().day(), Thursday);
	}
	date scheduler::last_friday() const { 
		date d(_year, _month, 1);
		return findday(1, d.end_of_month().day(), Friday);
	}
	date scheduler::last_saturday() const { 
		date d(_year, _month, 1);
		return findday(1, d.end_of_month().day(), Saturday);
	}
	date scheduler::last_sunday() const { 
		date d(_year, _month, 1);
		return findday(1, d.end_of_month().day(), Sunday);
	}

}  // namespace meetup
