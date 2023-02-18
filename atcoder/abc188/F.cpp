#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;
using LL = long long;

LL dfs(LL t, LL y, map<LL, LL>& memo) {
    if(y <= t) {
        return t - y;
    }

    if(memo.find(y) != memo.end()) {
        return memo[y];
    }

    LL res = 0LL;
    if(y & 1LL) {
        res = min(dfs(t, y + 1LL, memo), dfs(t, y - 1LL, memo)) + 1LL;
    } else {
        res = min(dfs(t, y / 2LL, memo) + 1LL, abs(t - y));
        //res = dfs(t, y / 2LL, memo) + 1LL;
    }

    memo[y] = res;

    return res;
}

void run_case() {
    LL X, Y;
    cin >> X >> Y;

    map<LL, LL> memo;

    cout << dfs(X, Y, memo) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
