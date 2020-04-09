/*
 * Problem: The Coin Change Problem
 * Link: https://www.hackerrank.com/challenges/coin-change/problem
 */

#include <bits/stdc++.h>

using namespace std;

long getWays(int n, const vector<long> &c) {
    vector<vector<long>> dp(n + 1, vector<long>(c.size(), 0));
    for (int i = 0; i < c.size(); i++)
        dp[0][i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < c.size(); j++)
            for (int k = j; k < c.size(); k++)
                if (c[k] <= i)
                    dp[i][j] += dp[i - c[k]][k];
    return dp[n][0];
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int n, m;
    cin >> n >> m;
    vector<long> c(m);
    for (int i = 0; i < m; i++)
        cin >> c[i];
    long ways = getWays(n, c);
    fout << ways << "\n";
    fout.close();
    return 0;
}
