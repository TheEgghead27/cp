#include <bits/stdc++.h>
using namespace std;

string recurse(string s, int start, int end, int target, bool large) {  // O(n!) solution, TLE
        int newstart;
        if (target == 0)
                return "";  // base case, nothing to get, nothing to give
        char buf;
        if (large)
                buf = 0; // null to start
        else
                buf = 127;
        for (int i = start; i < end-(target-1); i++) {
                if ((large && (s[i] > buf)) || (!large && (s[i] < buf))) {
                        if (start == 0 && s[i] == '0')
                                continue;  // skip since we can't have leading 0
                        buf = s[i];
                        newstart = i+1;
                }
        }
        return buf + recurse(s, newstart, end, target-1, large);
}


string quad(int n, int k, string s, bool larger) {
//        cout << "lin called " << larger << '\n';
        // scan through the array linearly, populating as you go
        char base;
        if (larger)
                base = 0;  // smallest
        else
                base = 127;
        string buf(k+1,base);  // init a null string of length k
        for (int h = 0; h < n; h++) {  // h is the true string index
                // if char > buf, write in char
                for (int i = abs(min(0, n-(h+k))); i < k; i++) {  // i is the index of the buffer string
                        // the min operation ensures that we start further up if we're late in the array

                        if (i == 0 && s[h] == '0')
                                continue;  // skip leading 0

                        bool comparison;
                        if (larger)
                                comparison = (s[h] > buf[i]);  // true string char > buffer string char
                        else
                                comparison = (s[h] < buf[i]);

                        if (comparison) {
//                                cout << "found " << s[h] << " at " << h << " to be better than " << buf[i] << " at " << i << '\n';
                                buf[i] = s[h];  // write true string to buffer
                                for (int j = i+1; j < k; j++) {  // null following chars
                                        buf[j] = base;
                                }
                                break;
                        }
                }
        }
        buf[k] = '\n';

//        cout << "lin returns " << buf;
        return buf;
}

string solve(void) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

//        string small = recurse(s, 0, n, k, false);
//        string large = recurse(s, 0, n, k, true);
//        return small + "\n" + large + "\n";

        /*for (int i = 0; i < n-k; i++) {
                cout << s[i];

        }*/

        return quad(n, k, s, false) + quad(n, k, s, true);
}


int main(void) {
        int t;
        cin >> t;
        for (int i = 0; i < t; i++) {
                cout << solve();
        }
        return 0;
}