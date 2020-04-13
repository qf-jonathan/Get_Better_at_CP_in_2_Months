/*
 * Problem: Bishwock
 * Link: https://codeforces.com/problemset/problem/991/D
 * Greedy version
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    int n = a.size(), prev = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int curr = (a[i] == '0') + (b[i] == '0');
        prev += curr;
        if (prev >= 3) {
            ans++;
            prev -= 3;
        } else prev = curr;
    }
    cout << ans << endl;
    return 0;
}
