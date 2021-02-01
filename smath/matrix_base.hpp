#ifndef MATRIX_BASE_INCLUDED_
#define MATRIX_BASE_INCLUDED_

#include <initializer_list>

/*
TODO:
	determinant
	inverse
*/

namespace sm {
	
	template <unsigned H, unsigned W, typename T>
	class mat {
	private:
		T data[W * H];

	public:
		static constexpr unsigned height = H;
		static constexpr unsigned width  = W;

		// constructors
		mat() {
			/* construct an identity matrix */
			for(int x = 0; x < width; ++x)
				for(int y = 0; y < height; ++y)
					data[y * width + x] = (x == y) ? 1: 0;
		}

		mat(T value) {
			/* construct the matrix with "value" for all elements */
			for(int i = 0; i < width * height; ++i)
				data[i] = value;
		}

		mat( std::initializer_list<T> init_list ) {
			/* construct the matrix fron an initializer list */
			typename std::initializer_list<T>::iterator it = init_list.begin();
			for(int i = 0; i < width * height || it != init_list.end() ; ++i, ++it)
				data[i] = *it;
		}

		// operations
		mat<H, W, T> getTranspose() const {
			/* return a new matrix, transpose of the current one */
			mat<H, W, T> transpose;

			for(int x = 0; x < width; ++x)
				for(int y = 0; y < height; ++y)
					transpose(x, y) = this->operator()(y, x);

			return transpose;
		}

		inline T &operator()(int y, int x) {
			/* used to access elements in the matrix, INDICES STARTS AT 0 */
			return data[y * width + x];
		}

		inline const T &operator()(int y, int x) const{
			/* used to access elements in the matrix, INDICES STARTS AT 0 */
			return data[y * width + x];
		}

		inline const T *toPtr() const {
			/* used for opengl api, returns a pointer to the first element of the data array */
			return &data[0];
		}

		inline T *toPtr() {
			/* used for opengl api, returns a pointer to the first element of the data array */
			return &data[0];
		}

		// math operations
		mat<H, W, T> &operator*=( T n ) {
			for(int x = 0; x < width; ++x)
				for(int y = 0; y < height; ++y)
					this->operator()(y, x) *= n;
			return *this;
		}

		mat<H, W, T> &operator/=( T n ) {
			for(int x = 0; x < width; ++x)
				for(int y = 0; y < height; ++y)
					this->operator()(y, x) /= n;
			return *this;
		}

		mat<H, W, T> &operator+=( const mat<H, W, T> &other) {
			for(int x = 0; x < width; ++x)
				for(int y = 0; y < height; ++y)
					this->operator()(y, x) += other(y, x);
			return *this;
		}

		mat<H, W, T> &operator-=( const mat<H, W, T> &other) {
			for(int x = 0; x < width; ++x)
				for(int y = 0; y < height; ++y)
					this->operator()(y, x) -= other(y, x);
			return *this;
		}

		mat<H, W, T> &operator-() {
			/* negate all elements in a matrix */
			for(int x = 0; x < width; ++x)
				for(int y = 0; y < height; ++y)
					this->operator()(y, x) = -this->operator()(y, x);
				
			return *this;
		}
	};

	// operator overloading
	template <unsigned size_a, unsigned size_b, unsigned size_c, typename T>
	mat<size_a, size_c, T> operator*( const mat<size_a, size_b, T> &m1, const mat<size_b, size_c, T> &m2 ) {
		mat<size_a, size_c, T> res;
		for(int x = 0; x < size_c; ++x)
			for(int y = 0; y < size_a; ++y) {
				// dot product with the Xth col of m2 and the Yth row of m1
				T dot_product_result = 0.0f;
				for(int i = 0; i < size_b; ++i)
					dot_product_result += m1(y, i) * m2(i, x);
				res(y, x) = dot_product_result;
			}
		
		return res;
	}

	template <unsigned size_a, unsigned size_b, typename T>
	mat<size_a, size_b, T> operator*( mat<size_a, size_b, T> m,  T n ) {
		mat<size_a, size_b, T> res(m);
		res *= n;
		return res;
	}

	template <unsigned size_a, unsigned size_b, typename T>
	mat<size_a, size_b, T> operator/( mat<size_a, size_b, T> m, T n ) {
		mat<size_a, size_b, T> res(m);
		res /= n;
		return res;
	}

	template <unsigned size_a, unsigned size_b, typename T>
	mat<size_a, size_b, T> operator+( mat<size_a, size_b, T> m1, mat<size_a, size_b, T> m2 ) {
		mat<size_a, size_b, T> res(m1);
		res += m2;
		return res;
	}

	template <unsigned size_a, unsigned size_b, typename T>
	mat<size_a, size_b, T> operator-( mat<size_a, size_b, T> m1, mat<size_a, size_b, T> m2 ) {
		mat<size_a, size_b, T> res(m1);
		res -= m2;
		return res;
	}

	template <unsigned size_a, unsigned size_b>
	using matf = mat<size_a, size_b, float>;
	template <unsigned size_a, unsigned size_b>
	using matd = mat<size_a, size_b, double>;
	template <unsigned size_a, unsigned size_b>
	using mati = mat<size_a, size_b, int>;
	template <unsigned size_a, unsigned size_b>
	using matu = mat<size_a, size_b, unsigned>;

	template <typename T>
	using mat4 = mat<4, 4, T>;
	template <typename T>
	using mat3 = mat<3, 3, T>;
	template <typename T>
	using mat2 = mat<2, 2, T>;


	using mat4d = mat<4, 4, double>;
	using mat3d = mat<3, 3, double>;
	using mat2d = mat<2, 2, double>;
	using mat4f = mat<4, 4, float>;
	using mat3f = mat<3, 3, float>;
	using mat2f = mat<2, 2, float>;
	using mat4i = mat<4, 4, int>;
	using mat3i = mat<3, 3, int>;
	using mat2i = mat<2, 2, int>;
	using mat4u = mat<4, 4, unsigned>;
	using mat3u = mat<3, 3, unsigned>;
	using mat2u = mat<2, 2, unsigned>;

};

#endif