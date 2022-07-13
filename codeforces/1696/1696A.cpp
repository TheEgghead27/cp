#include <bits/stdc++.h>
using namespace std;

int solve(void) {
        int n, z;
        cin >> n >> z;
        int a[n+1]; // one index
        for (int i = 1; i < n+1; i++) {
                cin >> a[i];
        }

        int ans = 0;

        for (int i = 1; i < n+1; i++) {
                // &ing the z will always decrease it
                // but is decreasing good sometimes?
                // probably not

                ans = max(ans, a[i] | z);
        }

        return ans;
}


int main(void) {
        int t;
        cin >> t;
        for (int i = 0; i < t; i++) {
                cout << solve() << '\n';
        }
        return 0;
}