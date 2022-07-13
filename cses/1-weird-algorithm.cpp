#include <iostream>

int main() {
        long long int x;
        std::cin >> x;
        while (x > 1) {
                std::cout << x;
                if (x % 2) {  // odd
                        x *= 3;
                        x += 1;
                }
                else {
                        x /= 2;
                }
                std::cout << ' ';
        }
        std::cout << 1;
        return 0;
}