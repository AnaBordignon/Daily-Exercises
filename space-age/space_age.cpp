#include "space_age.h"

namespace space_age {
	space_age::space_age(long long input) {
		age = input;
	}
	int space_age::seconds() const{
		return age;
	}

	double space_age::on_earth() const {
		return (double)age / 31557600.0;
	}
	double space_age::on_saturn() const {
		return (double)age / (31557600.0 * 29.447498);
	}

	double space_age::on_mercury() const {
		return (double)age / 31557600.0 / 0.2408467;
	}

	double space_age::on_venus() const {
		return (double)age / 31557600.0 / 0.61519726;
	}

	double space_age::on_mars() const {
		return (double)age / 31557600.0 / 1.8808158;
	}

	double space_age::on_jupiter() const {
		return (double)age / 31557600.0 / 11.862615;
	}

	double space_age::on_neptune() const {
		return (double)age / 31557600.0 / 164.79132;
	}

	double space_age::on_uranus() const {
		return (double)age / 31557600.0 / 84.016846;
	}
}  // namespace space_age
