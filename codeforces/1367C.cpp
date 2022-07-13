#include <bits/stdc++.h>
using namespace std;

int solve(void) {
	int n, k, total = 0, dist = 0;
	cin >> n >> k;
	bool a[n];
	char buf;
	for (int i = 0; i < n; i++) {
		cin >> buf;
		a[i] = (buf == '1');

	}
	int target = k * 2 + 1;
	unsigned int dist_to_last_table = k;
	for (int i = 0; i < n; i++) {
		if (a[i]) {
			dist_to_last_table = 0;
		}
		else {
			dist_to_last_table++;
			if (dist_to_last_table == target) {
				total++;
				a[i-k] = true;
				dist_to_last_table = k;
			}
		}
	}
	if (dist_to_last_table > k) {
		total++;
	}
	

        return total;
}


int main(void) {
        int t;
        cin >> t;
        for (int i = 0; i < t; i++) {
                cout << solve() << '\n';
        }
        return 0;
}
