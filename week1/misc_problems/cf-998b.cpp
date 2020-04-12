/*
 * Problem: Cutting
 * Link: https://codeforces.com/contest/998/problem/B
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, b;
    cin >> n >> b;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> c;
    int e = a[0] % 2 == 0, o = a[0] % 2;
    for (int i = 1; i < n - 1; i++) {
        e += a[i] % 2 == 0;
        o += a[i] % 2;
        if (e == o) c.push_back(abs(a[i] - a[i + 1]));
    }
    vector<vector<int>> dp(c.size() + 1, vector<int>(b + 1, 0));
    for (int i = 1; i <= c.size(); i++) {
        for (int j = 1; j <= b; j++) {
            if (c[i - 1] <= j) dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i - 1]] + 1);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    cout << dp[c.size()][b] << endl;
    return 0;
}
