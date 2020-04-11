/*
 * Problem: Shashlik Cooking
 * Link: https://codeforces.com/problemset/problem/1040/B
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    k = k * 2 + 1;
    int v = (n + k - 1) / k;
    int ini = (n - k * (v - 1) - 1) / 2;
    cout << v << '\n';
    for (int i = 0; i < v; i++, ini += k) {
        if (i) cout << ' ';
        cout << ini + 1;
    }
    cout << '\n';
    return 0;
}
