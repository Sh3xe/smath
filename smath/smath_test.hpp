#ifndef SMATH_HPP
#define SMATH_HPP

#include <initializer_list>

namespace sm {
	template <unsigned H, unsigned W, typename T>
	class mat {
	private:
		T data[W * H];

	public:
		static constexpr unsigned height = H;
		static constexpr unsigned width  = W;

		// constructors
		mat();
		mat(T value);
		mat( std::initializer_list<T> init_list );

		// operations
		mat<H, W, T> getTranspose() const;
		inline T &operator()(int y, int x);
		inline const T &operator()(int y, int x) const;
		inline const T *toPtr() const;
		inline T *toPtr();

		// math operations
		mat<H, W, T> &operator*=( T n );
		mat<H, W, T> &operator/=( T n );
		mat<H, W, T> &operator+=( const mat<H, W, T> &other);
		mat<H, W, T> &operator-=( const mat<H, W, T> &other);
		mat<H, W, T> &operator-();
	};

	// operator overloading
	template <unsigned size_a, unsigned size_b, unsigned size_c, typename T>
	mat<size_a, size_c, T> operator*( const mat<size_a, size_b, T> &m1, const mat<size_b, size_c, T> &m2 );
	template <unsigned size_a, unsigned size_b, typename T>
	mat<size_a, size_b, T> operator*( mat<size_a, size_b, T> m,  T n );
	template <unsigned size_a, unsigned size_b, typename T>
	mat<size_a, size_b, T> operator/( mat<size_a, size_b, T> m, T n );
	template <unsigned size_a, unsigned size_b, typename T>
	mat<size_a, size_b, T> operator+( mat<size_a, size_b, T> m1, mat<size_a, size_b, T> m2 );
	template <unsigned size_a, unsigned size_b, typename T>
	mat<size_a, size_b, T> operator-( mat<size_a, size_b, T> m1, mat<size_a, size_b, T> m2 );

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