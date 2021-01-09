#include <iostream>
#include "smath/smath.hpp"

template <typename T>
void sLog(const sm::vec2<T> &vec) {
	std::cout << vec.x << ' ' << vec.y << std::endl;
}

template <typename T>
void sLog( const T &a) {
	std::cout << a << std::endl;
}

void sLog(const sm::vec3f &vec) {
	std::cout << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
}

void sLog(const sm::vec4f &vec) {
	std::cout << vec.x << ' ' << vec.y << ' ' << vec.z << ' ' << vec.w << std::endl;
}


template <unsigned H, unsigned W, typename T>
void sLog(const sm::mat<H, W, T> &mat) {
	for(int y = 0; y < H; ++y) {
		for(int x = 0; x < W; ++x)
			std::cout << mat(y, x) << ' ';
		std::cout << std::endl;
	}
}

int main() {

	sm::matd<2, 4> m1 = {
		2.3, 5.1, 9.0, 0.7,
		2.3, 6.4, 9.7, 2.0
	};

	sm::matd<4, 3> m2 = {
		2.0, 1.2, 3.0,
		4.0, 1.0, 1.1,
		3.3, 0.2, 4.1,
		9.9, 2.2, 2.2
	};

	sLog( m1 * m2 );

	return 0;
}