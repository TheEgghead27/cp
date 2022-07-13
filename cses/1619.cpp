#include <iostream>
#include <vector>
using namespace std;


int main(void) {
	int n;
	cin >> n;
	vector<pair<int,bool>> arr;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		arr.push_back(t);
		cin >> t;
		arr.push_back(-t);
	}
	int cur = 0, max = 0;
	/* iterate through a list of entries and exits, when we get an exit subtract, enter, add, somewhat like prefix sum */
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] > 0)
			cur++;
		else {
			if (cur > max) {
				max = cur;
			}
			cur--;
		}
	}
	cout << max;

	return 0;
}
