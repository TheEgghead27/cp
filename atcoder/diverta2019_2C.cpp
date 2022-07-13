// we need to minimize min
// 	for positive numbers, we subtract them from the smallest value
// 	for negative numbers, we subtract them from the largest value

#include <iostream>
#include <climits>
using namespace std;

int main(void) {
	int n, min = INT_MAX, max = INT_MIN;
	int mini = -1, maxi = -1;
	cin >> n;
	int a[n];
	pair<int,int> buf[n-1];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > max) {
			max = a[i];
			maxi = i;
		}
		else if (a[i] < min) {
			min = a[i];
			mini = i;
		}
	}
	int smol = min;
	for (int i = 0, j = 0; i < n; i++) {
		if (i == mini || i == maxi) continue;
		if (a[i] >= 0) {
			buf[j] = pair<int,int>(smol, a[i]);
			smol -= a[i];
		}
		else {
			buf[j] = pair<int,int>(max, a[i]);
			max -= a[i];
		}
		j++;  // increment separately from i
	};
	buf[n-2] = pair<int,int>(max, smol);


	cout << max - smol << '\n';
	for (long long i = 0; i < n-1; i++)
		cout << buf[i].first << ' ' << buf[i].second << '\n';

	return 0;
}
