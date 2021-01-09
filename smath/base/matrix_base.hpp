#ifndef MATRIX_BASE_INCLUDED_
#define MATRIX_BASE_INCLUDED_

#include <initializer_list>

/*
TODO:
	determinant
	inverse
*/

namespace sm {
	
	template <unsigned H, unsigned W>
	class Matrix {
	private:
		float data[W * H];

	public:
		static constexpr unsigned height = H;
		static constexpr unsigned width = W;

		// constructors
		Matrix() {
			/* construct an identity matrix */
			for(int x = 0; x < width; ++x)
				for(int y = 0; y < height; ++y)
					data[y * width + x] = (x == y) ? 1.0f: 0.0f;
		}

		Matrix(float value) {
			/* construct the matrix with "value" for all elements */
			for(int i = 0; i < width * height; ++i)
				data[i] = value;
		}

		Matrix( std::initializer_list<float> init_list ) {
			/* construct the matrix fron an initializer list */
			std::initializer_list<float>::iterator it = init_list.begin();
			for(int i = 0; i < width * height || it != init_list.end() ; ++i, ++it)
				data[i] = *it;
		}

		// operations
		Matrix<width, height> getTranspose() const {
			/* return a new matrix, transpose of the current one */
			Matrix<width, height> transpose;

			for(int x = 0; x < width; ++x)
				for(int y = 0; y < height; ++y)
					transpose(x, y) = this->operator()(y, x);

			return transpose;
		}

		inline float &operator()(int y, int x) {
			/* used to access elements in the matrix, INDICES STARTS AT 0 */
			return data[y * width + x];
		}

		inline const float &operator()(int y, int x) const{
			/* used to access elements in the matrix, INDICES STARTS AT 0 */
			return data[y * width + x];
		}

		inline const float *toPtr() const {
			/* used for opengl api, returns a pointer to the first element of the data array */
			return &data[0];
		}

		inline float *toPtr() {
			/* used for opengl api, returns a pointer to the first element of the data array */
			return &data[0];
		}

		// math operations

		Matrix<height, width> &operator*=( float n ) {
			for(int x = 0; x < width; ++x)
				for(int y = 0; y < height; ++y)
					this->operator()(y, x) *= n;
			return *this;
		}

		Matrix<height, width> &operator/=( float n ) {
			for(int x = 0; x < width; ++x)
				for(int y = 0; y < height; ++y)
					this->operator()(y, x) /= n;
			return *this;
		}

		Matrix<width, height> &operator+=( const Matrix<width, height> &other) {
			for(int x = 0; x < width; ++x)
				for(int y = 0; y < height; ++y)
					this->operator()(y, x) += other(y, x);
			return *this;
		}

		Matrix<width, height> &operator-=( const Matrix<width, height> &other) {
			for(int x = 0; x < width; ++x)
				for(int y = 0; y < height; ++y)
					this->operator()(y, x) -= other(y, x);
			return *this;
		}

		Matrix<height, width> &operator-() {
			/* negate all elements in a matrix */
			for(int x = 0; x < width; ++x)
				for(int y = 0; y < height; ++y)
					this->operator()(y, x) = -this->operator()(y, x);
				
			return *this;
		}
	};

	// operator overloading
	template <unsigned size_a, unsigned size_b, unsigned size_c>
	Matrix<size_a, size_c> operator*( const Matrix<size_a, size_b> &m1, const Matrix<size_b, size_c> &m2 ) {
		Matrix<size_a, size_c> res;
		for(int x = 0; x < size_c; ++x)
			for(int y = 0; y < size_a; ++y) {
				// dot product with the Xth col of m2 and the Yth row of m1
				float dot_product_result = 0.0f;
				for(int i = 0; i < size_b; ++i)
					dot_product_result += m1(y, i) * m2(i, x);
				res(y, x) = dot_product_result;
			}
		
		return res;
	}

	template <unsigned size_a, unsigned size_b>
	Matrix<size_a, size_b> operator*( Matrix<size_a, size_b> m,  float n ) {
		Matrix<size_a, size_b> res(m);
		res *= n;
		return res;
	}

	template <unsigned size_a, unsigned size_b>
	Matrix<size_a, size_b> operator/( Matrix<size_a, size_b> m, float n ) {
		Matrix<size_a, size_b> res(m);
		res /= n;
		return res;
	}

	template <unsigned size_a, unsigned size_b>
	Matrix<size_a, size_b> operator+( Matrix<size_a, size_b> m1, Matrix<size_a, size_b> m2 ) {
		Matrix<size_a, size_b> res(m1);
		res += m2;
		return res;
	}

	template <unsigned size_a, unsigned size_b>
	Matrix<size_a, size_b> operator-( Matrix<size_a, size_b> m1, Matrix<size_a, size_b> m2 ) {
		Matrix<size_a, size_b> res(m1);
		res -= m2;
		return res;
	}

	template <unsigned height, unsigned width>
	using mat = Matrix<height, width>;

	using mat4 = Matrix<4, 4>;
	using mat3 = Matrix<3, 3>;
	using mat2 = Matrix<2, 2>;

};

#endif