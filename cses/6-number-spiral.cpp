#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		unsigned int x, y;
		cin >> y >> x;
		unsigned long long loop = max(y, x), a;
		// odd loop starts at 1, y
		// even loop starts at x, 1
		// end of a loop is loop^2
		// beginning of a loop is (loop-1)^2 + 1
		if (x >= y) {  // we're on the vertical part of a loop
			if (loop % 2) {  // odd loop, we count down from the end
				a = (loop * loop) - (y - 1);
			}
			else {  // even loop, we count up from the beginning
				a = (loop - 1) * (loop - 1) + y;
			}
		}
		else {  // we're on a horizontal loop
			if (loop % 2) {  // odd loop, we count up from the beginning
				a = (loop - 1) * (loop - 1) + x;
			}
			else {  // even loop, we count down from the end
				a = (loop * loop) - (x - 1);
			}
		}
		cout << a << '\n';
	}
	return 0;
}
