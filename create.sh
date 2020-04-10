#!/bin/bash

if [ $1 == 'cpp' ]
then
cat <<END
/*
 * Problem:
 * Link:
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("../input.txt", "r", stdin);
    return 0;
}
END
fi