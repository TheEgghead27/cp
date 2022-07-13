// this came to me in a dream
#include <bits/stdc++.h>
using namespace std;

// possible to optimize to short if low on memory
int base[5][4] = {{-1}, {-1}, {-1}, {3, 1, 4, 2}};
vector<int*> mem(base, base+4);   // 0-3 cases are nulled, 4 is a base case

void solve(int n) {  // writes answer to global array	
#ifdef _DEBUG
			cout << "current mem size(): " << mem.size() << "\n";
#endif
	if (mem.size() >= n) {  // return mem cache hit if less
#ifdef _DEBUG
		cout << "cache hit\n";
#endif
		return; // mem.at(n)
	}

#ifdef _DEBUG
	cout << "solving fr, a starts at " << mem.size() + 1 <<"\n";
#endif
	// else, add new numbers to the sides of the array (literally impossible to have issue because alternating 👍)
	for (int a = mem.size() + 1; a < n+1; a++) {
		int *arr = new int[a];  // this is getting to a n^2 stage wuh-oh
		bool isOdd = a % 2;
#ifdef _DEBUG
		cout << "isOdd " << isOdd << "; a-isOdd " << a-isOdd << "\n";
#endif

		for (int i = isOdd; i < a; i++) {
			arr[i] = mem.at(a-2)[i-isOdd];
#ifdef _DEBUG
			cout << "wrote " << arr[i] << " at " << i << "\n";
#endif
		}
		if (isOdd) { // odd, prepend
			arr[0] = a;
#ifdef _DEBUG
			cout << "prepended " << arr[0] << " for " << a << "\n";
#endif
		}
		else { // even, append
			arr[a-1] = a;
#ifdef _DEBUG
			cout << "appended " << arr[a-1] << " for " << a << "\n";
#endif
		}

		mem.push_back(arr);
#ifdef _DEBUG
		cout << "pushed\n";
#endif
	}


	return;


}

int main(void) {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		if (n < 4) {  // impossible
#ifdef _DEBUG
			cout << "base case\n";
#endif
			cout << -1 << '\n';
		}
		else {
#ifdef _DEBUG
			cout << "solving\n";
#endif
			solve(n);

#ifdef _DEBUG
			cout << "solved " << n << " \n";
#endif
			for (int j = 0; j < n; j++) {
				cout << mem.at(n-1)[j] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}
