#if !defined(GIGASECOND_H)
#define GIGASECOND_H

#include "boost/date_time/posix_time/posix_time.hpp"

namespace gigasecond {

	using namespace  boost::posix_time;

	ptime advance(ptime input);
}  // namespace gigasecond

#endif // GIGASECOND_H