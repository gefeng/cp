#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = (LL)1e9 + 7LL;

void run_case() {
    int S;
    cin >> S;

    if(S < 3) {
        cout << 0 << '\n';
        return;
    }

    // [3, 2000] 
    vector<LL> dp(S + 1, 0LL);
    vector<LL> ds(S + 2, 0LL);
    dp[0] = 1LL;
    for(int i = 0; i < 3; i++) {
        ds[i + 1] = 1;
    }

    for(int i = 3; i <= S; i++) {
        // i - min(i, S) i - 3
        int l = i - min(i, S);
        int r = i - 3;
        dp[i] += (ds[r + 1] - ds[l] + MOD) % MOD;
        dp[i] %= MOD;
        ds[i + 1] = ds[i] + dp[i];
        /*for(int j = 3; j <= min(i, S); j++) {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }*/
    }

    cout << dp[S] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
