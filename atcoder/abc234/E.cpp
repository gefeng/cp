#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL INF = 2e18;

LL dfs(LL X, LL cur) {
    if(cur >= X) {
        return cur;
    }

    LL res = INF;
    if(cur == 0) {
        for(int i = 1; i < 10; i++) {
            res = min(res, dfs(X, i));
        } 
    } else if(cur < 10) {
        for(int i = 0; i < 10; i++) {
            res = min(res, dfs(X, cur * 10 + i));
        }
    } else {
        int d1 = cur % 10;
        int d2 = cur / 10 % 10;
        int d = d1 - (d2 - d1);
        if(d >= 0 && d < 10) {
            res = min(res, dfs(X, cur * 10 + d));
        }
    }

    return res;
}

void run_case() {
    LL X;
    cin >> X;

    cout << dfs(X, 0LL) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
