/*
 * Problem: Functions again
 * Link: https://codeforces.com/problemset/problem/788/A
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, p = INT_MIN;
    cin >> n;
    vector<int> l, r;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (p != INT_MIN) {
            l.push_back(abs(p - a));
            r.push_back(abs(p - a));
        }
        p = a;
    }
    for (int i = 0; i < n - 1; i += 2) {
        l[i] *= -1;
        if (i + 1 < n - 1) r[i + 1] *= -1;
    }
    auto mx = [](const vector<int> &v) -> long long {
        long long m = 0, s = 0;
        for (int i: v) {
            s = max(0LL + i, s + i);
            m = max(m, s);
        }
        return m;
    };
    cout << max(mx(l), mx(r)) << endl;
    return 0;
}
