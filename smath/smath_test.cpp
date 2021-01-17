#include "smath_test.hpp"

namespace sm {
	template <unsigned H, unsigned W, typename T>
	mat<H, W, T>::mat() {
		/* construct an identity matrix */
		for(int x = 0; x < width; ++x)
			for(int y = 0; y < height; ++y)
				data[y * width + x] = (x == y) ? 1: 0;
	}

	template <unsigned H, unsigned W, typename T>
	mat<H, W, T>::mat(T value) {
		/* construct the matrix with "value" for all elements */
		for(int i = 0; i < width * height; ++i)
			data[i] = value;
	}

	template <unsigned H, unsigned W, typename T>
	mat<H, W, T>::mat( std::initializer_list<T> init_list ) {
		/* construct the matrix fron an initializer list */
		typename std::initializer_list<T>::iterator it = init_list.begin();
		for(int i = 0; i < width * height || it != init_list.end() ; ++i, ++it)
			data[i] = *it;
	}

	// operations
	template <unsigned H, unsigned W, typename T>
	mat<H, W, T> mat<H, W, T>::getTranspose() const {
		/* return a new matrix, transpose of the current one */
		mat<H, W, T> transpose;

		for(int x = 0; x < width; ++x)
			for(int y = 0; y < height; ++y)
				transpose(x, y) = this->operator()(y, x);

		return transpose;
	}

	template <unsigned H, unsigned W, typename T>
	inline T &mat<H, W, T>::operator()(int y, int x) {
		/* used to access elements in the matrix, INDICES STARTS AT 0 */
		return data[y * width + x];
	}

	template <unsigned H, unsigned W, typename T>
	inline const T &mat<H, W, T>::operator()(int y, int x) const{
		/* used to access elements in the matrix, INDICES STARTS AT 0 */
		return data[y * width + x];
	}

	template <unsigned H, unsigned W, typename T>
	inline const T *mat<H, W, T>::toPtr() const {
		/* used for opengl api, returns a pointer to the first element of the data array */
		return &data[0];
	}

	template <unsigned H, unsigned W, typename T>
	inline T *mat<H, W, T>::toPtr() {
		/* used for opengl api, returns a pointer to the first element of the data array */
		return &data[0];
	}

	// math operations
	template <unsigned H, unsigned W, typename T>
	mat<H, W, T> &mat<H, W, T>::operator*=( T n ) {
		for(int x = 0; x < width; ++x)
			for(int y = 0; y < height; ++y)
				this->operator()(y, x) *= n;
		return *this;
	}

	template <unsigned H, unsigned W, typename T>
	mat<H, W, T> &mat<H, W, T>::operator/=( T n ) {
		for(int x = 0; x < width; ++x)
			for(int y = 0; y < height; ++y)
				this->operator()(y, x) /= n;
		return *this;
	}

	template <unsigned H, unsigned W, typename T>
	mat<H, W, T> &mat<H, W, T>::operator+=( const mat<H, W, T> &other) {
		for(int x = 0; x < width; ++x)
			for(int y = 0; y < height; ++y)
				this->operator()(y, x) += other(y, x);
		return *this;
	}

	template <unsigned H, unsigned W, typename T>
	mat<H, W, T> &mat<H, W, T>::operator-=( const mat<H, W, T> &other) {
		for(int x = 0; x < width; ++x)
			for(int y = 0; y < height; ++y)
				this->operator()(y, x) -= other(y, x);
		return *this;
	}

	template <unsigned H, unsigned W, typename T>
	mat<H, W, T> &mat<H, W, T>::operator-() {
		/* negate all elements in a matrix */
		for(int x = 0; x < width; ++x)
			for(int y = 0; y < height; ++y)
				this->operator()(y, x) = -this->operator()(y, x);
			
		return *this;
	}

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
};