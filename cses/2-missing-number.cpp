#include <iostream>
#include <vector>
#include <algorithm>

int gen()
{
        static int i = 0;
        return ++i;
}

bool check(int i, int j) {return (i < j);}

int main() {
        int n;
        std::cin >> n;
        // long int* arr = new long int [n - 1];
        std::vector<long long> refArr(n);
        long long refSum = 0;
        std::generate(refArr.begin(), refArr.end(), gen);
        std::vector<long long>::iterator i1;
        for (i1 = refArr.begin(); i1 != refArr.end(); ++i1)
                refSum += *i1;
        // delete &refArr;


        std::vector<long long> arr(n-1);
        for (int i = 0; i < n-1; i++) {
#ifdef DEBUG
                std::cout << "testing " <<  i << '\n';
#endif
                std::cin >> arr[i];
        }

        std::sort(arr.begin(), arr.end(), check);



        /*
        std::cout << '[';
        // for (int i = 0; i < n ; i++)
                // std::cout << refArr[i] << ", ";
        for (i1 = refArr.begin(); i1 != refArr.end(); ++i1)
                std::cout << *i1 << ", ";
        std::cout << ']';
         */

        //std::cout << '[';
        // for (int i = 0; i < n ; i++)
                // std::cout << arr[i] << ", ";
        long long newSum = 0;
        for (i1 = arr.begin(); i1 != arr.end(); ++i1)
                newSum += *i1;
                // std::cout << *i1 << ", ";
        //std::cout << ']';
#ifdef DEBUG
        std::cout << refSum << '\t' << newSum << '\n';
#endif
        std::cout << refSum - newSum;


        return 0;
}