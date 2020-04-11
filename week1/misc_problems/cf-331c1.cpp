/*
 * Problem: The Great Julya Calendar
 * Link: https://codeforces.com/problemset/problem/331/C1
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        bool d[10] = {};
        int t = i;
        while (t) {
            d[t % 10] = true;
            t /= 10;
        }
        for (int j = 1; j < 10; j++) {
            if (d[j] && j <= i)
                dp[i] = min(dp[i], dp[i - j] + 1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
