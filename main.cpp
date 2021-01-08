#include <iostream>
#include "smath.hpp"

void log(const sm::vec2f &vec) {
	std::cout << vec.x << ' ' << vec.y << std::endl;
}

void log(const sm::vec3f &vec) {
	std::cout << vec.x << ' ' << vec.y << ' ' << vec.z << std::endl;
}

template <unsigned H, unsigned W>
void log(sm::mat<H, W> mat) {
	for(int y = 0; y < H; ++y) {
		for(int x = 0; x < W; ++x)
			std::cout << mat(y, x) << ' ';
		std::cout << std::endl;
	}
}

int main() {

	sm::mat<3, 2> A {
		1.f, 2.4f,
		5.3f, 2.22f,
		1.f, 0.f
	};

	sm::mat<2, 5> B {
		1.f, 2.f, 3.f, 1.f, 2.f,
		0.2543f, 2.f, 2.f, 3.f, 44.f
	};

	log( A * B );

	return 0;
}