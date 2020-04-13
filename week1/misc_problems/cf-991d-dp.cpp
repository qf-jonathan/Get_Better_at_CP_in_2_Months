/*
 * Problem: Bishwock
 * Link: https://codeforces.com/problemset/problem/991/D
 * Dynamic Programming version
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    vector<int> dp(a.size() + 1, 0);
    for (int i = 1; i <= a.size(); i++) {
        int cu = (a[i - 1] == '0') + (b[i - 1] == '0');
        int p1 = i - 2 >= 0 ? (a[i - 2] == '0') + (b[i - 2] == '0') : 0;
        int p2 = i - 3 >= 0 ? (a[i - 3] == '0') + (b[i - 3] == '0') : 0;
        int p3 = i - 4 >= 0 ? (a[i - 4] == '0') + (b[i - 4] == '0') : 0;
        if (cu == 0) dp[i] = dp[i - 1];
        else if (cu == 1) {
            if (p1 < 2) dp[i] = dp[i - 1];
            else {
                if (p2 == 0) dp[i] = dp[i - 1] + 1;
                else dp[i] = dp[i - 2] + 1;
            }
        } else {
            if (p1 == 0) dp[i] = dp[i - 1];
            else if (p1 == 1) {
                if (p2 == 2) dp[i] = dp[i - 2] + 1;
                else dp[i] = dp[i - 1] + 1;
            } else {
                if (p2 == 0) dp[i] = dp[i - 1] + 1;
                else if (p2 == 1) dp[i] = dp[i - 2] + 1;
                else {
                    if (p3 == 0) dp[i] = dp[i - 1] + 1;
                    else dp[i] = dp[i - 3] + 2;
                }
            }
        }
    }
    cout << dp[a.size()] << '\n';
    return 0;
}
