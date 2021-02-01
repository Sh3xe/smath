#ifndef CONVERSIONS_INCLUDED_
#define CONVERSIONS_INCLUDED_

#include "constants.hpp"

namespace sm {
	double radToDeg( double radian ) {
		return (360.0*radian) / TWOPI;
	}

	double degToRad( double degree ) {
		return (degree * TWOPI) / 360.0;
	}
}

#endif