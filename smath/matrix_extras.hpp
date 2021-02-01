/* TODO:
	# AXIS ALIGNED AND ARBITRARY ORIENTED
	scale
	skew
	reflection
	perspective projection
	orthographic projection

	orthogonalize

*/

#ifndef MATRIX_EXTRAS_INCLUDED_
#define MATRIX_EXTRAS_INCLUDED_

#include "matrix_base.hpp"
#include "vector3_base.hpp"

#include <iostream>
#include <cmath>

namespace sm {
	template<typename T>
	mat4<T> getTranslate( const vec3<T> &v ) {
		return mat4<T> {
			1.0, 0.0, 0.0, 0.0,	
			0.0, 1.0, 0.0, 0.0,	
			0.0, 0.0, 1.0, 0.0,	
			v.x, v.y, v.z, 1.0
		};
	}

	template <typename T>
	mat4<T> getRotationAboutX( double thetha_rad ) {
		double cos_thetha = cos(thetha_rad);
		double sin_thetha = sin(thetha_rad);
		return mat4<T> {
			1.0, 0.0        , 0.0       , 0.0,
			0.0, cos_thetha , sin_thetha, 0.0,
			0.0, -sin_thetha, cos_thetha, 0.0,
			0.0, 0.0        , 0.0       , 1.0
		};
	};

	template <typename T>
	mat4<T> getRotationAboutY( double thetha_rad ) {
		double cos_thetha = cos(thetha_rad);
		double sin_thetha = sin(thetha_rad);
		return mat4<T> {
			cos_thetha, 0.0, -sin_thetha, 0.0,
			0.0       , 1.0, 0.0        , 0.0,
			sin_thetha, 0.0, cos_thetha , 0.0,
			0.0       , 0.0, 0.0        , 1.0
		};
	};

	template <typename T>
	mat4<T> getRotationAboutZ( double thetha_rad ) {
		double cos_thetha = cos(thetha_rad);
		double sin_thetha = sin(thetha_rad);
		return mat4<T> {
			cos_thetha , sin_thetha, 0.0, 0.0,
			-sin_thetha, cos_thetha, 0.0, 0.0,
			0.0        , 0.0       , 1.0, 0.0,
			0.0        , 0.0       , 0.0, 1.0
		};
	};

	template <typename T>
	mat4<T> getRotation( double thetha_rad, const sm::vec3<T> &vec ) {
		double cos_thetha = cos(thetha_rad);
		double sin_thetha = sin(thetha_rad);
		return mat4<T> {
			vec.x*vec.x*(1.0-cos_thetha) + cos_thetha    , vec.x*vec.y*(1.0-cos_thetha) + vec.z*sin_thetha, vec.x*vec.z*(1.0-cos_thetha)-vec.y*sin_thetha, 0.0,
			vec.x*vec.y*(1.0-cos_thetha)-vec.z*sin_thetha, vec.y*vec.y*(1.0-cos_thetha)+cos_thetha        , vec.y*vec.z*(1.0-cos_thetha)+vec.x*sin_thetha, 0.0,
			vec.x*vec.z*(1.0-cos_thetha)+vec.y*sin_thetha, vec.y*vec.z*(1.0-cos_thetha)-vec.x*sin_thetha  , vec.z*vec.z*(1.0-cos_thetha)+cos_thetha      , 0.0,
			0.0                                          , 0.0                                            , 0.0                                          , 1.0
		};
	}
	
	template <typename T>
	mat4<T> getProjection (double fov, double ratio, double far, double close) {
		return mat4<T>();
	}
};

#endif