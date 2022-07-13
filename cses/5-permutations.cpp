#include <algorithm>
#include <iostream>
#include <vector>

int gen() {
        static int i = 0;
        return ++i;
}

bool is_beautiful(std::vector<int> arr) {
        std::vector<int>::iterator i;
        for (i = arr.begin(), i++; i != arr.end(); i += 2)
                if ((std::abs((*(i - 1)) - (*i)) == 1) || (std::abs((*(i + 1)) - (*i)) == 1))
                        return false;
        return true;
}

int findInt(std::vector<int> arr, int target) {
        for (int i = 0; i < arr.size(); i++)
                if (arr[i] == target)
                        return i;
        return -1;
}


std::vector<int> generate_arrays(std::vector<int> arr, int index = 0) {
        for (int i = 1; i <= arr.size(); i++) {
                if (index >= arr.size())
                        return arr;  // ending case of recursions

                if (findInt(arr, i) != -1)
                        continue;  // we cant have duplicates

#ifdef DEBUG
                std::cout << "\narr index: " << index << '\n';
#endif
                arr[index] = i;
                arr = generate_arrays(arr, index + 1);
                if (arr.size() == 0)
                        continue;
                if (is_beautiful(arr))
                        return arr;
        }
        return std::vector<int>(0);
}

void PRINT_ARR(std::vector<int> arr, int size) {
        std::cout << '[';
        for (int i = 0; i < size; i++)
                std::cout << arr[i] << ", ";
        std::cout << "]\n";
}

void gen_arr_test(int arr[], int size, int index = 0) {
        for (int i = 1; i <= size; i++) {
                if (index >= size)
                        return;

                if (findInt(arr, i) > -1)
                        continue;

                arr[index] = i;
                gen_arr_test(arr, size, index + 1);

                if (index == 0)
                        PRINT_ARR(arr, size);
        }
}


int main() {
        int n;
        std::cin >> n;

        std::vector<int> arr(n);
        // std::generate(arr.begin(), arr.end(), gen);

        arr = generate_arrays(arr);

#ifdef DEBUG
        /*
        std::cout << '[';
        for (int i = 0; i < n; i++)
                std::cout << arr[i] << ", ";
        std::cout << ']';
         */
        PRINT_ARR(arr, n);
#endif
        std::cout << is_beautiful(arr);
        return 0;
}