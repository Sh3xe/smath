#ifndef CONVERSIONS_INCLUDED_
#define CONVERSIONS_INCLUDED_

#include "../base/constants.hpp"

namespace sm {
	double radToDeg( double degree ) {
		return (360.0*degree)/TWOPI;
	}
}

#endif