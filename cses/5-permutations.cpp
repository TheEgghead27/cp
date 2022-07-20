#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	if (n < 4)
		cout << "NO SOLUTION\n";
	else {
		int b;
		for (b = n - (n % 2); b > 4; b-=2) {
			cout << b << ' ';
		}
		cout << 2 << ' ';
		cout << 4 << ' ';
		cout << 1 << ' ';
		cout << 3 << ' ';
		for (b = 5; b <= n; b+=2) {
			cout << b << ' ';
		}

	}

	return 0;
}
