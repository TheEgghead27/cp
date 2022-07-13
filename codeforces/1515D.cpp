#include <bits/stdc++.h>
using namespace std;

int solve(void) {  // Total: O(n)
	int n, l, r, buf;
	cin >> n >> l >> r;
        int colors[n];
        for (int i = 0; i < n; i++)  // O(n) operation, 0 out the array
                colors[i] = 0;

        // O(n) operation, scan in the numbers
        for (int i = 0; i < l; i++) {
                cin >> buf;
                colors[buf-1]++;  // colors are 1 indexed, we're 0 indexing
        }
        for (int i = 0; i < r; i++) {
                cin >> buf;
                colors[buf-1]--;
        }

        int pos = 0, neg = 0;
        for (int i = 0; i < n; i++) {  // O(n) agai(n) for polarity counts
                if (colors[i] > 0) pos+=colors[i]; else if (colors[i] < 0) neg-=colors[i];
#ifdef _DEBUG
                cout << colors[i] << ' ';  // debug
#endif
        }
#ifdef _DEBUG
        cout << '\n';
        cout << pos << ' ' << neg << '\n';
#endif

        int flips = abs(pos - neg) / 2;  // disparity of right to left, divided by 2 for # of flips
        int ops = flips;  // start operation count with flips
        bool noPos = pos > neg;

        for (int i = 0; i < n; i++) {  // scan through the array for pairs we can make with 1 flip - (O(n))
                if (noPos) {  // need to get rid of positives
                        if (colors[i] > 1) {  // flip left socks to make pairs
                                while (flips > 0 && colors[i] > 1) {
                                        colors[i] -= 2;
                                        flips--;
                                        pos -= 2;
                                }
                        }
                }
                else { // need to get rid of negatives
                        if (colors[i] < -1) {  // flip right socks to make pairs
                                while (flips > 0 && colors[i] < -1) {
                                        colors[i] += 2;
                                        flips--;
                                        neg -= 2;
                                }
                        }
                }
        }
        if (flips) {  // still have some remaining flips to flip off, offload on the nearest thing you can find - O(n)
                for (int i = 0; i < n && flips > 0; i++) {
                        if (noPos) {
                                if (colors[i] == 1) {  // because any other positive values would have been flipped off
                                        colors[i] = -1;
                                        flips--;
                                }
                        }
                        else {
                                if (colors[i] == -1) {  // because any other negative values would have been flipped off
                                        colors[i] = +1;
                                        flips--;
                                }
                        }
                }
        }
#ifdef _DEBUG
        cout << "\nList: ";
#endif
        for (int i = 0; i < n; i++) {  // O(n)
#ifdef _DEBUG
                cout << colors[i] << ' ';
#endif
                if (colors[i] > 0)
                        ops += colors[i];
        }
#ifdef _DEBUG
        cout << '\n';
#endif

        return ops;


        /*
	vector<int> left, right;
	//int left[l], right[r];

	// cout << l << ' ' << r;

	// O(l * r) operation: naive scan through left and right socks for immediate matches
	// ok this was a bad idea
	{
		vector<int> *larger, *smaller;
		if (l < r) { // r is greater
			larger = &right;

			smaller = &left;
		}
		else {
			larger = &left;

			smaller = &right;
		}

		vector<pair<int,int>> del_targ;

		for (int i = 0; i < larger -> size(); i++) {
			for (int j = 0; j < smaller -> size(); j++)
				if (larger -> at(i) == smaller -> at(j)) {
					pair<int,int> tmp = {i,j};
					del_targ.push_back(tmp);
				}
		}
		for (int i = del_targ.size() - 1; i >= 0; i--) {
			cout << i;
			larger -> erase(larger->begin()+del_targ[i].first);
			smaller->erase(smaller->begin()+del_targ[i].second);
		}
	}
	for (int i: right)
		cout << i << ' ';
	cout << '\n';
	for (int i: left)
		cout << i << ' ';
	cout << '\n';
        */
}


int main(void) {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		cout << solve() << "\n\n";
	return 0;
}
