/* TODO:
	# AXIS ALIGNED AND ARBITRARY ORIENTED
	rotation
	translation
	scale
	skew
	reflection
	perspective projection
	orthographic projection

	orthogonalize

*/

#ifndef MATRIX_EXTRAS_INCLUDED_
#define MATRIX_EXTRAS_INCLUDED_

#include "../base/matrix_base.hpp"
#include "../base/vector3_base.hpp"

#include <iostream>
namespace sm {

	template<typename T>
	mat4<T> &translate( mat4<T> &m, const vec3f &v) {
		/*  translate m by c,
			return a reference to m;
		*/
		m(3, 0) += v.x;
		m(3, 1) += v.y;
		m(3, 2) += v.z;

		return m;
	}

	template<typename T>
	mat4<T> getTranslate( const mat4<T> &m, const vec3<T> &v ) {
		mat4<T> result = m;
		return translate(result, v);
	}



};

#endif