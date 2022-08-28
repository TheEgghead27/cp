#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solve() {
	int n, k;
	cin >> n >> k;

	int s[101] = {0}, buf, total = 0;
	vector<int> check;
	for (int i = 0; i < n; i++) {
		cin >> buf;
		s[buf]++;
		if (find(check.begin(), check.end(), buf) == check.end()) {
			check.push_back(buf);
		}
		total++;
	}
	if (total > (2 * k))
		return false;
	for (int i : check) {
		if (s[i] > 2)
			return false;
	}
	return true;
}

int main(void) {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		if(solve())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
