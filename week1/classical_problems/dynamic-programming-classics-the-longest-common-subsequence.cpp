/*
 * Problem: The Longest Common Subsequence
 * Link: https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> longestCommonSubsequence(const vector<int> &a, const vector<int> &b) {
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    vector<int> ans;
    int pi = a.size(), pj = b.size();
    while (pi > 0 && pj > 0) {
        if (a[pi - 1] == b[pj - 1]) {
            ans.push_back(a[pi - 1]);
            pi--, pj--;
        } else if (dp[pi - 1][pj] > dp[pi][pj - 1]) pi--;
        else pj--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    auto ans = longestCommonSubsequence(a, b);
    for (int i = 0; i < ans.size(); i++) {
        if (i) fout << ' ';
        fout << ans[i];
    }
    fout << '\n';
    return 0;
}
