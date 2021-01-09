#ifndef VECTOR3_BASE_INCLUDED_
#define VECTOR3_BASE_INCLUDED_

#include <cmath>
#include "matrix_base.hpp"

namespace sm {

	template<typename T>
	struct Vector3 {
		// data
		union {
			struct { T x, y, z; };
			struct { T r, g, b; };
		};

		// constructors
		Vector3() = default;

		Vector3( T n ) : x(n), y(n), z(n) {}
		Vector3( T x, T y, T z ): x(x), y(y), z(z) {}
		
		Vector3( const Vector3<T> &vec ): x(vec.x), y(vec.y), z(vec.z) {}

		Vector3<T> &operator=( const Vector3<T> &other ) {
			this->x = other.x;
			this->y = other.y;

			return *this;
		}

	};

	struct Vector3f {
		// data
		union {
			struct { float x, y, z; };
			struct { float r, g, b; };
		};

		// constructors & copy control
		Vector3f() = default;
		Vector3f( float n ): x(n), y(n), z(n) {}
		Vector3f( float x, float y, float z ): x(x), y(y), z(z) {}

		Vector3f( const Vector3<float> &vec_f ): x(vec_f.x), y(vec_f.y), z(vec_f.z) {}
		Vector3f( const Vector3f &vec ): x(vec.x), y(vec.y), z(vec.z) {}

		Vector3f &operator=( const Vector3f &other ) {
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;

			return *this;
		}

		Vector3f &operator=( const Vector3<float> &other ) {
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;

			return *this;
		}

		// operations
		Vector3f &operator+=( float n ) {
			this->x += n;
			this->y += n;
			this->z += n;

			return *this;
		}

		Vector3f &operator-=( float n ) {
			this->x -= n;
			this->y -= n;
			this->z -= n;

			return *this;
		}

		Vector3f &operator*=( float n ) {
			this->x *= n;
			this->y *= n;
			this->z *= n;

			return *this;
		}

		Vector3f &operator/=( float n ) {
			this->x /= n;
			this->y /= n;
			this->z /= n;

			return *this;
		}


		Vector3f &operator+=( const Vector3f &other ) {
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;

			return *this;
		}

		Vector3f &operator-=( const Vector3f &other ) {
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;

			return *this;
		}

		Vector3f &operator*=( const Vector3f &other ) {
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;

			return *this;
		}

		Vector3f &operator/=( const Vector3f &other ) {
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;

			return *this;
		}


		Vector3f &operator*=( const Matrix<3, 3> &m ) {
			this->x = m(0, 0) * this->x + m(1, 0) * this->y + m(2, 0) * this->z;
			this->y = m(0, 1) * this->x + m(1, 1) * this->y + m(2, 1) * this->z;
			this->z = m(0, 2) * this->x + m(1, 2) * this->y + m(2, 2) * this->z;

			return *this;
		}


		float length() {
			return sqrt( x*x + y*y + z*z );
		}

		Vector3f &normalize() {
			float length = this->length();

			this->x /= length;
			this->y /= length;
			this->z /= length;

			return *this;
		}

		Vector3f getNormalized() {
			Vector3f result = *this;
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
	Vector3f operator+( const Vector3f &right, float n ) {
		Vector3f result = right;
		return result += n;
	}

	Vector3f operator-( const Vector3f &right, float n ) {
		Vector3f result = right;
		return result -= n;
	}

	Vector3f operator*( const Vector3f &right, float n ) {
		Vector3f result = right;
		return result *= n;
	}

	Vector3f operator/( const Vector3f &right, float n ) {
		Vector3f result = right;
		return result /= n;
	}


	Vector3f operator+( const Vector3f &right, const Vector3f &left ) {
		Vector3f result = right;
		return result += left;
	}

	Vector3f operator-( const Vector3f &right, const Vector3f &left ) {
		Vector3f result = right;
		return result -= left;
	}


	Vector3f operator*( const Vector3f &v, const Matrix<3, 3> &m ) {
		Vector3f result = v;
		return result *= m;
	}


	float dot( const Vector3f &right, const Vector3f &left ) {
		/* mathematical dot product */
		return right.x * left.x + right.y * left.y + right.z * left.z;
	}

	Vector3f cross( const Vector3f &right, const Vector3f &left ) { // A VERIFIER
		/* mathematical cross product */
		Vector3f result;

		result.x = (right.y * left.z) - (right.z * left.y);
		result.y = (right.z * left.x) - (right.x * left.z);
		result.z = (right.x * left.y) - (right.y * left.x);

		return result;
	}

	// using declarations
	template <typename T>
	using vec3 = Vector3<T>;

	using vec3f = Vector3f;

};

#endif