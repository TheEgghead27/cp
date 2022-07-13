#include <bits/stdc++.h>
using namespace std;

void solve(void) {
	signed int n, k;
	cin >> n >> k;
	if (
		((n % 2) && !(k % 2))  || // n is odd but [k is even | ]
		((k % 2) && (n % 2) && (k > n)) ||  // k is odd, but we cant fit enough 1's into an odd n
		(!(n % 2) && ((k * (k%2 + 1)) > n))  // n is even, but we cant fit enough 1/2's (k even/odd) into n 
	) {	
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	signed int bound;
	short isEven = 1 + (short)(k % 2 && !(n % 2));
	/*if (n % 2) {  // n is odd*/
		bound = k - 1;  // leave the last 1 for later
		for (int i = 0; i < bound; i++) {  // bound is guaranteed to be even (odd - odd[1] = even)
			cout << isEven << ' ';
			n -= isEven;  // thus polarity of n will be the same at the end, odd
		}
	/*}
	else {  // n is even
		if (k % 2) {  // k is odd, we need to spit out even numbers
			bound = (k / 2) - 1;
			for (int i = 0; i < bound; i++) {
				cout << "2 ";
				n -= 2;
			}
		}
		else {  // k is even, we need to spit out 
		
		}
	}*/
	cout << n << '\n';

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
