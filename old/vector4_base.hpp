#ifndef VECTOR4_BASE_INCLUDED_
#define VECTOR4_BASE_INCLUDED_

#include <cmath>
#include "matrix_base.hpp"

// TODO: GROSSE VERIFICATION

namespace sm {

	template<typename T>
	struct Vector4 {
		/* used only for storing 4 elements of a same type, no math operations */

		// data
		union {
			struct { T x, y, z, w; };
			struct { T r, g, b, a; };
		};

		// constructors
		Vector4() = default;

		Vector4( T n ) : x(n), y(n), z(n), w(n) {}
		Vector4( T x, T y, T z, T w ): x(x), y(y), z(z), w(w) {}
		
		Vector4( const Vector4<T> &vec ): x(vec.x), y(vec.y), z(vec.z), w(vec.w) {}

		Vector4<T> &operator=( const Vector4<T> &other ) {
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			this->w = other.w;

			return *this;
		}

	};

	struct Vector4f {
		/* Used for math operations */

		// data
		union {
			struct { float x, y, z, w; };
			struct { float r, g, b, a; };
		};

		// constructors & copy control
		Vector4f() = default;
		Vector4f( float n ): x(n), y(n), z(n), w(n) {}
		Vector4f( float x, float y, float z, float w ): x(x), y(y), z(z), w(w) {}

		Vector4f( const Vector4<float> &vec_f ): x(vec_f.x), y(vec_f.y), z(vec_f.z), w(vec_f.w) {}
		Vector4f( const Vector4f &vec ): x(vec.x), y(vec.y), z(vec.z), w(vec.w) {}

		Vector4f &operator=( const Vector4f &other ) {
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			this->w = other.w;

			return *this;
		}

		Vector4f &operator=( const Vector4<float> &other ) {
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			this->w = other.w;

			return *this;
		}

		// operations
		Vector4f &operator+=( float n ) {
			this->x += n;
			this->y += n;
			this->z += n;
			this->w += n;

			return *this;
		}

		Vector4f &operator-=( float n ) {
			this->x -= n;
			this->y -= n;
			this->z -= n;
			this->w -= n;

			return *this;
		}

		Vector4f &operator*=( float n ) {
			this->x *= n;
			this->y *= n;
			this->z *= n;
			this->w *= n;

			return *this;
		}

		Vector4f &operator/=( float n ) {
			this->x /= n;
			this->y /= n;
			this->z /= n;
			this->w /= n;

			return *this;
		}


		Vector4f &operator+=( const Vector4f &other ) {
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			this->w += other.w;

			return *this;
		}

		Vector4f &operator-=( const Vector4f &other ) {
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			this->w -= other.w;

			return *this;
		}


		Vector4f &operator*=( const Matrix<4, 4> &m ) {
			this->x = m(0, 0) * this->x + m(1, 0) * this->y + m(2, 0) * this->z + m(3, 0) * this->w;
			this->y = m(0, 1) * this->x + m(1, 1) * this->y + m(2, 1) * this->z + m(3, 1) * this->w;
			this->z = m(0, 2) * this->x + m(1, 2) * this->y + m(2, 2) * this->z + m(3, 2) * this->w;
			this->w = m(0, 3) * this->x + m(1, 3) * this->y + m(2, 3) * this->z + m(3, 3) * this->w;

			return *this;
		}


		float length() {
			return sqrt( x*x + y*y + z*z + w*w );
		}

		Vector4f &normalize() {
			float length = this->length();

			this->x /= length;
			this->y /= length;
			this->z /= length;
			this->w /= length;

			return *this;
		}

		Vector4f getNormalized() {
			Vector4f result = *this;
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
	Vector4f operator+( const Vector4f &right, float n ) {
		Vector4f result = right;
		return result += n;
	}

	Vector4f operator-( const Vector4f &right, float n ) {
		Vector4f result = right;
		return result -= n;
	}

	Vector4f operator*( const Vector4f &right, float n ) {
		Vector4f result = right;
		return result *= n;
	}

	Vector4f operator/( const Vector4f &right, float n ) {
		Vector4f result = right;
		return result /= n;
	}


	Vector4f operator+( const Vector4f &right, const Vector4f &left ) {
		Vector4f result = right;
		return result += left;
	}

	Vector4f operator-( const Vector4f &right, const Vector4f &left ) {
		Vector4f result = right;
		return result -= left;
	}


	Vector4f operator*( const Vector4f &v, const Matrix<4, 4> &m ) {
		Vector4f result = v;
		return result *= m;
	}


	float dot( const Vector4f &right, const Vector4f &left ) {
		return right.x * left.x + right.y * left.y + right.z * left.z + right.w * left.w;
	}

	// using declarations
	template <typename T>
	using vec4 = Vector4<T>;

	using vec4f = Vector4f;

};

#endif