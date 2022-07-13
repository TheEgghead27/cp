#include <bits/stdc++.h>
using namespace std;

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

        if (bs != as) {  // impossible, sums dont align
                cout << "sum issue\n";
                return false;
        }

        int i = 0;
        for (int j = 0; j < k && i < n; j++) {
                if (b[j] == a[i]) {
                        i++;
                        continue;
                }
                else if (b[j] == a[i] / m) {
                        n += m - 1;
                        a.insert(a.begin()+i,m-1,a[i]/m);
                        i++;
                }
                else if (b[j] == (a[i] * m)) {
                        printf("a[i] %d [%d], m %d, b[j] %d [%d]\n", a[i], i, m, b[j], j);
                        int targ = m;
                        for (int k = i; i < n && targ > 0; i++) {
                                // printf("scanning %d and %d under %d\n", a[i], a[k], m);
                                if (a[i] == a[k]) {
                                        targ--;
                                }
                                else if (a[i] / m == a[k]) {
                                        targ -= m;
                                        n += m - 1;
                                        a.insert(a.begin() + i, m - 1, a[i] / m);
                                        k += m - 2;
                                        i = k;
                                }
                                else {
                                        cout << targ << " bruh!\n";
                                        return false;
                                }

                        }
                }
                else {
                        printf("FAIL: a[i] %d [%d], m %d, b[j] %d [%d]\n", a[i], i, m, b[j], j);
                        return false;
                }

        }

        // cout << "final\n";
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