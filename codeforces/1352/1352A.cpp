#include <bits/stdc++.h>
using namespace std;

void solve(void) {
	string s;
	cin >> s;
	short len = s.length();
	vector<short> ans;
	for (int i = 0; i < len; i++) {
		if (s[i] != '0') {
			ans.push_back((s[i] - '0') * pow(10, (len - i - 1)));
		}
	}

	cout << ans.size() << '\n';
	for(short i : ans)
		cout << i << ' ';
	cout << '\n';
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
