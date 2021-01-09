#ifndef VECTOR2_BASE_INCLUDED_
#define VECTOR2_BASE_INCLUDED_

#include <cmath>
#include "matrix_base.hpp"

namespace sm {

	template <typename T>
	struct vec2 {
		// data
		union {
			struct { T x, y; };
			struct { T r, g; };
		};

		// constructors & copy control
		vec2() = default;

		vec2( T n ): x(n), y(n) {}
		vec2( T x, T y ): x(x), y(y) {}

		// operations
		vec2<T> &operator+=( T n ) {
			/* adds n to each "*this" elements */
			x += n;
			y += n;

			return *this;
		}

		vec2<T> &operator-=( T n ) {
			/* substract n to each "*this" elements */
			x -= n;
			y -= n;

			return *this;
		}

		vec2<T> &operator*=( T n ) {
			/* multiply n to each "*this" elements */
			x *= n;
			y *= n;

			return *this;
		}

		vec2<T> &operator/=( T n ) {
			/* divide n to each *this elements */
			x /= n;
			y /= n;

			return *this;
		}


		vec2<T> &operator+=( const vec2<T> &other ) {
			/* vector-vector addition */
			x += other.x;
			y += other.y;

			return *this;
		}

		vec2<T> &operator-=( const vec2<T> &other ) {
			/* vector-vector substraction */
			x -= other.x;
			y -= other.y;

			return *this;
		}


		vec2<T> &operator*=( const mat<2, 2, T> &m ) {
			x = m(0, 0) * x + m(1, 0) * y;
			y = m(0, 1) * x + m(1, 1) * y;

			return *this;
		}


		double length() {
			return sqrt( x*x + y*y );
		}

		vec2<T> &normalize() {
			double length = this->length();
			x /= length;
			y /= length;

			return *this;
		}

		vec2<T> getNormalized() {
			/* get a copy of the normalized version of "*this" */
			vec2 result = *this;
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
	vec2<T> operator+( const vec2<T> &right, T n ) {
		vec2<T> result = right;
		return result += n;
	}

	template <typename T>
	vec2<T> operator-( const vec2<T> &right, T n ) {
		vec2<T> result = right;
		return result -= n;
	}

	template <typename T>
	vec2<T> operator*( const vec2<T> &right, T n ) {
		vec2<T> result = right;
		return result *= n;
	}

	template <typename T>
	vec2<T> operator/( const vec2<T> &right, T n ) {
		vec2<T> result = right;
		return result /= n;
	}


	template <typename T>
	vec2<T> operator+( const vec2<T> &right, const vec2<T> &left ) {
		vec2<T> result = right;
		result += left;

		return result;
	}

	template <typename T>
	vec2<T> operator-( const vec2<T> &right, const vec2<T> &left ) {
		vec2<T> result = right;
		result -= left;

		return result;
	}


	template <typename T>
	vec2<T> operator*( const vec2<T> &v, const mat<2, 2, T> &m ) {
		vec2<T> result = v;
		return result *= m;
	}


	template <typename T>
	T dot( const vec2<T> &right, const vec2<T> &left ) {
		/* mathematical dot product */
		return right.x * left.x + right.y * left.y;
	}

	// using declarations
	using vec2f = vec2<float>;
	using vec2d = vec2<double>;
	using vec2i = vec2<int>;
	using vec2u = vec2<unsigned>;

};

#endif