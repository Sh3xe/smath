#ifndef VECTOR2_BASE_INCLUDED_
#define VECTOR2_BASE_INCLUDED_

#include <cmath>
#include "matrix_base.hpp"

namespace sm {

	template<typename T>
	struct Vector2 {
		// data
		union {
			struct { T x, y; };
			struct { T r, g; };
		};

		// constructors
		Vector2() = default;

		Vector2( T n) : x(n), y(n) {}
		Vector2( T x, T y ): x(x), y(y) {}

		Vector2<T> &operator=(const Vector2<T> &vec) {
			this->x = vec.x;
			this->y = vec.y;

			return *this;
		}

	};

	struct Vector2f {
		// data
		union {
			struct { float x, y; };
			struct { float r, g; };
		};

		// constructors & copy control
		Vector2f() = default;
		Vector2f( float n ): x(n), y(n) {}
		Vector2f( float x, float y ): x(x), y(y) {}

		Vector2f( const Vector2<float> &vec_f ): x(vec_f.x), y(vec_f.y) {}

		Vector2f &operator=( const Vector2f &vec_f ) {
			this->x = vec_f.x;
			this->y = vec_f.y;
			return *this;
		}

		Vector2f &operator=( const Vector2<float> &vec_f ) {
			this->x = vec_f.x;
			this->y = vec_f.y;
			return *this;
		}

		// operations
		Vector2f &operator+=( float n ) {
			/* adds n to each "*this" elements */
			this->x += n;
			this->y += n;

			return *this;
		}

		Vector2f &operator-=( float n ) {
			/* substract n to each "*this" elements */
			this->x -= n;
			this->y -= n;

			return *this;
		}

		Vector2f &operator*=( float n ) {
			/* multiply n to each "*this" elements */
			this->x *= n;
			this->y *= n;

			return *this;
		}

		Vector2f &operator/=( float n ) {
			/* divide n to each *this elements */
			this->x /= n;
			this->y /= n;

			return *this;
		}


		Vector2f &operator+=( const Vector2f &other ) {
			/* vector-vector addition */
			this->x += other.x;
			this->y += other.y;

			return *this;
		}

		Vector2f &operator-=( const Vector2f &other ) {
			/* vector-vector substraction */
			this->x -= other.x;
			this->y -= other.y;

			return *this;
		}


		Vector2f &operator*=( const Matrix<2, 2> &m ) {
			this->x = m(0, 0) * this->x + m(1, 0) * this->y;
			this->y = m(0, 1) * this->x + m(1, 1) * this->y;

			return *this;
		}


		float length() {
			return sqrt( x*x + y*y );
		}

		Vector2f &normalize() {
			float length = this->length();
			this->x /= length;
			this->y /= length;

			return *this;
		}

		Vector2f getNormalized() {
			/* get a copy of the normalized version of "*this" */
			Vector2f result = *this;
			return result.normalize();
		}

		inline const float *toPtr() const {
			/* used for opengl api, returns a pointer to the first element of the vector */
			return &x;
		}

		inline float *toPtr() {
			/* used for opengl api, returns a pointer to the first element of the vector */
			return &x;
		}

	};

	// oparations
	Vector2f operator+( const Vector2f &right, float n ) {
		Vector2f result = right;
		return result += n;
	}

	Vector2f operator-( const Vector2f &right, float n ) {
		Vector2f result = right;
		return result -= n;
	}

	Vector2f operator*( const Vector2f &right, float n ) {
		Vector2f result = right;
		return result *= n;
	}

	Vector2f operator/( const Vector2f &right, float n ) {
		Vector2f result = right;
		return result /= n;
	}


	Vector2f operator+( const Vector2f &right, const Vector2f &left ) {
		Vector2f result = right;
		result += left;

		return result;
	}

	Vector2f operator-( const Vector2f &right, const Vector2f &left ) {
		Vector2f result = right;
		result -= left;

		return result;
	}


	Vector2f operator*( const Vector2f &v, const Matrix<2, 2> &m ) {
		Vector2f result = v;
		return result *= m;
	}


	float dot( const Vector2f &right, const Vector2f &left ) {
		/* mathematical dot product */
		return right.x * left.x + right.y * left.y;
	}

	// using declarations
	template <typename T>
	using vec2 = Vector2<T>;

	using vec2f = Vector2f;

};

#endif