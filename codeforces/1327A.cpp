#include <iostream>

int main(void) {
	int total;
	unsigned int x, y;

	std::cin >> total;

	for (int i = 0; i < total; i++) {
		std::cin >> x >> y;
		if (((x / 2) >= y) && ((x % 2) ? (y % 2) : (!(y % 2)))) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
	

	return 0;
}
