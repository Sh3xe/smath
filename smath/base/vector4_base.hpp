#ifndef VECTOR4_BASE_INCLUDED_
#define VECTOR4_BASE_INCLUDED_

#include <cmath>
#include "matrix_base.hpp"

namespace sm {

	template <typename T>
	struct vec4 {
		// data
		union {
			struct { T x, y, z, w; };
			struct { T r, g, b, a; };
		};

		// constructors & copy control
		vec4() = default;

		vec4( T n ): x(n), y(n), z(n), w(n) {}
		vec4( T x, T y, T z, T w ): x(x), y(y), z(z), w(w) {}

		// operations
		vec4<T> &operator+=( T n ) {
			/* adds n to each "*this" elements */
			x += n;
			y += n;
            z += n;
			w += n;

			return *this;
		}

		vec4<T> &operator-=( T n ) {
			/* substract n to each "*this" elements */
			x -= n;
			y -= n;
            z -= n;
			w -= n;

			return *this;
		}

		vec4<T> &operator*=( T n ) {
			/* multiply n to each "*this" elements */
			x *= n;
			y *= n;
            z *= n;
			w *= n;

			return *this;
		}

		vec4<T> &operator/=( T n ) {
			/* divide n to each *this elements */
			x /= n;
			y /= n;
            z /= n;
			w /= n;

			return *this;
		}


		vec4<T> &operator+=( const vec4<T> &other ) {
			/* vector-vector addition */
			x += other.x;
			y += other.y;
            z += other.z;
			w += other.w;

			return *this;
		}

		vec4<T> &operator-=( const vec4<T> &other ) {
			/* vector-vector substraction */
			x -= other.x;
			y -= other.y;
            z -= other.z;
			w -= other.w;

			return *this;
		}


		vec4<T> &operator*=( const Matrix<2, 2> &m ) {
			x = m(0, 0) * x + m(1, 0) * y + m(2, 0) * z + m(3, 0) * w;
			x = m(0, 1) * x + m(1, 1) * y + m(2, 1) * z + m(3, 1) * w;
			x = m(0, 2) * x + m(1, 2) * y + m(2, 2) * z + m(3, 2) * w;
			x = m(0, 3) * x + m(1, 3) * y + m(2, 3) * z + m(3, 3) * w;

			return *this;
		}


		double length() {
			return sqrt( x*x + y*y + z*z + w*w );
		}

		vec4<T> &normalize() {
			double length = length();
			x /= length;
			y /= length;
			z /= length;
			w /= length;

			return *this;
		}

		vec4<T> getNormalized() {
			/* get a copy of the normalized version of "*this" */
			vec4 result = *this;
			return result.normalize();
		}

		inline const T *toPtr() const {
			/* used for opengl api, returns a pointer to the first element of the vector */
			return &x;
		}

		inline T *toPtr() {
			/* used for opengl api, returns a pointer to the first element of the vector */
			return &x;
		}

	};

	// oparations
	template <typename T>
	vec4<T> operator+( const vec4<T> &right, T n ) {
		vec4<T> result = right;
		return result += n;
	}

	template <typename T>
	vec4<T> operator-( const vec4<T> &right, T n ) {
		vec4<T> result = right;
		return result -= n;
	}

	template <typename T>
	vec4<T> operator*( const vec4<T> &right, T n ) {
		vec4<T> result = right;
		return result *= n;
	}

	template <typename T>
	vec4<T> operator/( const vec4<T> &right, T n ) {
		vec4<T> result = right;
		return result /= n;
	}


	template <typename T>
	vec4<T> operator+( const vec4<T> &right, const vec4<T> &left ) {
		vec4<T> result = right;
		result += left;

		return result;
	}

	template <typename T>
	vec4<T> operator-( const vec4<T> &right, const vec4<T> &left ) {
		vec4<T> result = right;
		result -= left;

		return result;
	}


	template <typename T>
	vec4<T> operator*( const vec4<T> &v, const Matrix<2, 2> &m ) {
		vec4<T> result = v;
		return result *= m;
	}


	template <typename T>
	T dot( const vec4<T> &right, const vec4<T> &left ) {
		/* mathematical dot product */
		return right.x * left.x + right.y * left.y + right.z * left.z + right.w * left.w;
	}

	// using declarations
	using vec4f = vec4<float>;
	using vec4d = vec4<double>;
	using vec4i = vec4<int>;
	using vec4u = vec4<unsigned>;

};

#endif