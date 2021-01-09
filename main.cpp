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

template <unsigned H, unsigned W>
void sLog(sm::mat<H, W> mat) {
	for(int y = 0; y < H; ++y) {
		for(int x = 0; x < W; ++x)
			std::cout << mat(y, x) << ' ';
		std::cout << std::endl;
	}
}

int main() {

	sm::vec2d vec1 {0.024, 95.33};
	sm::vec2d vec2 {2.223, 5.624};

	sm::vec2d vec3 {1.0, 2.0};

	sLog( dot(vec1, vec2) );

	sLog( vec3 * 2.0 );
	sLog( vec3 + 2.0 );
	sLog( vec3 - 2.0 );
	sLog( vec3 / 2.0 );

	sLog( vec3 + vec1 );
	sLog( vec3 - vec1 );

	return 0;
}