#include <bits/stdc++.h>
using namespace std;

int solve(void) {
        int n;
        cin >> n;
        unsigned int buf, ans = 0;
        bool streak = false;
        for (int i = 0; i < n; i++) {
                cin >> buf;
                if (buf != 0){
                        if (!streak) {
                                ans++;
                                streak = true;
                        }
                }
                else {
                        streak = false;
                }
        }

        return min(ans, (unsigned int) 2);
}


int main(void) {
        int t;
        cin >> t;
        for (int i = 0; i < t; i++) {
                cout << solve() << '\n';
        }
        return 0;
}