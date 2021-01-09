#ifndef VECTOR3_BASE_INCLUDED_
#define VECTOR3_BASE_INCLUDED_

#include <cmath>
#include "matrix_base.hpp"

namespace sm {

	template <typename T>
	struct vec3 {
		// data
		union {
			struct { T x, y, z; };
			struct { T r, g, b; };
		};

		// constructors & copy control
		vec3() = default;

		vec3( T n ): x(n), y(n), z(n) {}
		vec3( T x, T y, T z ): x(x), y(y), z(z) {}

		// operations
		vec3<T> &operator+=( T n ) {
			/* adds n to each "*this" elements */
			x += n;
			y += n;
            z += n;

			return *this;
		}

		vec3<T> &operator-=( T n ) {
			/* substract n to each "*this" elements */
			x -= n;
			y -= n;
            z -= n;

			return *this;
		}

		vec3<T> &operator*=( T n ) {
			/* multiply n to each "*this" elements */
			x *= n;
			y *= n;
            z *= n;

			return *this;
		}

		vec3<T> &operator/=( T n ) {
			/* divide n to each *this elements */
			x /= n;
			y /= n;
            z /= n;

			return *this;
		}


		vec3<T> &operator+=( const vec3<T> &other ) {
			/* vector-vector addition */
			x += other.x;
			y += other.y;
            z += other.z;

			return *this;
		}

		vec3<T> &operator-=( const vec3<T> &other ) {
			/* vector-vector substraction */
			x -= other.x;
			y -= other.y;
            z -= other.z;

			return *this;
		}


		vec3<T> &operator*=( const Matrix<2, 2> &m ) {
			x = m(0, 0) * x + m(1, 0) * y + m(2, 0) * z;
			x = m(0, 1) * x + m(1, 1) * y + m(2, 1) * z;
			x = m(0, 2) * x + m(1, 2) * y + m(2, 2) * z;

			return *this;
		}


		double length() {
			return sqrt( x*x + y*y + z*z );
		}

		vec3<T> &normalize() {
			double length = length();
			x /= length;
			y /= length;
			z /= length;

			return *this;
		}

		vec3<T> getNormalized() {
			/* get a copy of the normalized version of "*this" */
			vec3 result = *this;
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
	vec3<T> operator+( const vec3<T> &right, T n ) {
		vec3<T> result = right;
		return result += n;
	}

	template <typename T>
	vec3<T> operator-( const vec3<T> &right, T n ) {
		vec3<T> result = right;
		return result -= n;
	}

	template <typename T>
	vec3<T> operator*( const vec3<T> &right, T n ) {
		vec3<T> result = right;
		return result *= n;
	}

	template <typename T>
	vec3<T> operator/( const vec3<T> &right, T n ) {
		vec3<T> result = right;
		return result /= n;
	}


	template <typename T>
	vec3<T> operator+( const vec3<T> &right, const vec3<T> &left ) {
		vec3<T> result = right;
		result += left;

		return result;
	}

	template <typename T>
	vec3<T> operator-( const vec3<T> &right, const vec3<T> &left ) {
		vec3<T> result = right;
		result -= left;

		return result;
	}


	template <typename T>
	vec3<T> operator*( const vec3<T> &v, const Matrix<2, 2> &m ) {
		vec3<T> result = v;
		return result *= m;
	}


	template <typename T>
	T dot( const vec3<T> &right, const vec3<T> &left ) {
		/* mathematical dot product */
		return right.x * left.x + right.y * left.y + right.z * left.z;
	}

	template <typename T>
	vec3<T> cross( const vec3<T> &right, const vec3<T> &left ) { // A VERIFIER
		/* mathematical cross product */
		vec3<T> result;

		result.x = (right.y * left.z) - (right.z * left.y);
		result.y = (right.z * left.x) - (right.x * left.z);
		result.z = (right.x * left.y) - (right.y * left.x);

		return result;
	}

	// using declarations
	using vec3f = vec3<float>;
	using vec3d = vec3<double>;
	using vec3i = vec3<int>;
	using vec3u = vec3<unsigned>;

};

#endif