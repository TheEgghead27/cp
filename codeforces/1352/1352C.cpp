#include <bits/stdc++.h>
using namespace std;

long long solve(void) {
	long long n, k;
	cin >> n >> k;
	long long ans = ((n * k) / (n - 1));
	if (!(ans % n))
		ans--;  // subtract one, we hit a step too far up
	else if (ans == -1)
		ans = n+1;
	return ans;
}


int main(void) {
        int t;
        cin >> t;
        for (int i = 0; i < t; i++) {
                cout << solve() << '\n';
        }
        return 0;
}
