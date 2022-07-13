#include <iostream>
#include <vector>

int main() {
        int n;
        std::cin >> n;
        std::vector<long long> arr(n);
        long long max = 0;
        for (int i = 0; i < n; i++) {
                std::cin >> arr[i];
                if (i >= 1)  // dont want to go under our bounds
                {
                        if (arr[i] < arr[i - 1]) { // the thing after is less than the thing before
                                max += arr[i - 1] - arr[i];  // find the number of steps to take
                                arr[i] = arr[i - 1]; // set the thing to the right place
                        }
                }
        }
        std::cout << max;
#ifdef DEBUG
        std::cout << '[';
        for (int i = 0; i < n; i++)
                std::cout << arr[i] << ", ";
        std::cout << ']';
#endif


        return 0;
}