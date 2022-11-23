#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = 998244353LL;

void run_case() {
    int N;
    cin >> N;

    vector<LL> dp(10, 0LL);
    for(int i = 1; i <= 9; i++) {
        dp[i] = 1LL;
    }

    for(int i = 2; i <= N; i++) {
        vector<LL> ndp(10, 0LL);
        for(int j = 1; j <= 9; j++) {
            ndp[j] += dp[j];
            if(j > 1) {
                ndp[j] += dp[j - 1];
                ndp[j] %= MOD;
            }
            if(j < 9) {
                ndp[j] += dp[j + 1];
                ndp[j] %= MOD;
            }
        }
        dp = ndp;
    }

    LL ans = 0LL;
    for(int i = 1; i <= 9; i++) {
        ans += dp[i];
        ans %= MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
