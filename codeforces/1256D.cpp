#include <bits/stdc++.h>
using namespace std;

void solve(void) {
	long long n, k;
	cin >> n >> k;
	char buf;
	string a;
	cin >> a;
	long long far = -1, dist;
	for (int i = 0; i < n && k > 0; i++) {
		if (a[i] == '0') {
			a[i] = '1';
			// "move" it up
			dist = i - (far + 1);
			if (k >= dist) {
				k -= dist;
				far = i - dist;
				a[far] = '0';
				
			}
			else {
				far = i - k;
				k = 0;
				a[far] = '0';
			}
		}
	}
	cout << a << '\n';


        return;
}


int main(void) {
        int t;
        cin >> t;
        for (int i = 0; i < t; i++) {
                solve();
        }
        return 0;
}
