/*
 * Problem: Knapsack
 * Link: https://www.hackerrank.com/challenges/unbounded-knapsack/problem
 */

#include <bits/stdc++.h>

using namespace std;

int unboundedKnapsack(int k, const vector<int> &arr) {
    vector<bool> dp(k + 1, false);
    dp[0] = true;
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < arr.size(); j++)
            if (arr[j] <= i)
                dp[i] = dp[i] || dp[i - arr[j]];
        if (dp[i]) ans = i;
    }
    return ans;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int result = unboundedKnapsack(k, arr);
        fout << result << "\n";
    }
    fout.close();
    return 0;
}
