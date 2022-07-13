#include <bits/stdc++.h>
using namespace std;

int canMake(vector<int> &as, int x, int i, int m, int times = 1) {
        if (times < 1)
                return 0;
        int ans = 0;
        int j = as.at(x);
                if (i == j) {
                        ans = x + 1;
                }

                else {
                        if (j / m == i) {
                                as.erase(std::next(as.begin(), x));
                                as.insert(as.begin()+x, m, (j / m));
                                ans = x + 1;
                        } else if (j * m == i) {
                                ans = canMake(as, x+1, j, m-1);
                        }
                }


        if (ans && times-1 > 0)
                ans = canMake(as, x+1, j, times-1);


        return ans;
}

bool solve(void) {
        int n, m;
        cin >> n >> m;
        vector<int> a;
        int as = 0, buf;
        for (int i = 0; i < n; i++) {
                cin >> buf;
                a.push_back(buf);
                as += buf;
        }

        int k;
        cin >> k;
        vector<int> b;
        int bs = 0;
        for (int i = 0; i < k; i++) {
                cin >> buf;
                b.push_back(buf);
                bs += buf;
        }

        if (bs != as)  // impossible, sums dont align
                return false;

        int x;
        for (int i : b) {
                x = canMake(a,x,i,m);
                if (!x)
                        return false;
        }
        return true;
}


int main(void) {
        int t;
        cin >> t;
        for (int i = 0; i < t; i++) {
                if (solve())
                        cout << "Yes" << '\n';
                else
                        cout << "No" << '\n';
        }
        return 0;
}