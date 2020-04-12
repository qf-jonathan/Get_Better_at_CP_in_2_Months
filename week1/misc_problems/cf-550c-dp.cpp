/*
 * Problem: Divisibility by Eight
 * Link: https://codeforces.com/problemset/problem/550/C
 * Dynamic Programming version
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;
    vector<vector<bool>> dp(n.size() + 1, vector<bool>(8, false));
    vector<vector<int>> pr(n.size() + 1, vector<int>(8, -1));
    int pi = -1, pj = 0;
    for (int i = 1; i <= n.size() && pi == -1; i++) {
        dp[i][(n[i - 1] - '0') % 8] = true;
        for (int j = 0; j < 8; j++) {
            if (dp[i - 1][j]) {
                int curr = (j * 10 + (n[i - 1] - '0')) % 8;
                dp[i][j] = dp[i][curr] = true;
                pr[i][j] = pr[i][curr] = j;
            }
        }
        if (dp[i][0]) pi = i;
    }
    if (pi != -1) {
        string ans;
        while (true) {
            if (pr[pi][pj] == -1 || pr[pi][pj] != pj)
                ans.append(1, n[pi - 1]);
            if (pr[pi][pj] == -1) break;
            pj = pr[pi][pj];
            pi--;
        }
        reverse(ans.begin(), ans.end());
        cout << "YES\n" << ans << '\n';
    } else {
        cout << "NO\n";
    }
    return 0;
}
