/*
 * Problem: Divisibility by Eight
 * Link: https://codeforces.com/problemset/problem/550/C
 * Math version (division by 8 property)
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;
    for (int i = 0; i < n.size(); i++) {
        int d1 = n[i] - '0';
        if (d1 % 8 == 0) {
            cout << "YES\n" << d1 << '\n';
            return 0;
        }
        for (int j = i + 1; j < n.size(); j++) {
            int d2 = (n[i] - '0') * 10 + (n[j] - '0');
            if (d2 % 8 == 0) {
                cout << "YES\n" << d2 << '\n';
                return 0;
            }
            for (int k = j + 1; k < n.size(); k++) {
                int d3 = (n[i] - '0') * 100 + (n[j] - '0') * 10 + (n[k] - '0');
                if (d3 % 8 == 0) {
                    cout << "YES\n" << d3 << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "NO\n";
    return 0;
}
