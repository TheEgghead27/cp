#include <bits/stdc++.h>
using namespace std;

bool solve(void) {
	int n, buf;
	cin >> n;
	int ar[n];
	bool res = true;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	vector<int> a;
	for (int i = 0; i < n; i++) {
		// buf = ar[i] + ar[abs(ar[i] % n)];
		buf = i + 1 + ar[abs((ar[i]) % n)];
		//buf = i + ar[ar[i] % n];
		if (res) {
			buf += (buf % n);
			if( find(a.begin(), a.end(), buf) != a.end() ) {  // found
				res = false;
				cerr << "something mapped onto " << buf << '\n';
			}
			a.push_back(buf);
		}
	}

        return res;
}

// i quit screw this


int main(void) {
        int t;
        cin >> t;
        for (int i = 0; i < t; i++) {
                if (solve())
		       cout << "YES\n";
		else
			cout << "NO\n";
        }
        return 0;
}
