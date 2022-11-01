#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = (LL)998244353;

LL q_pow(LL x, LL y) {
    LL res = 1LL;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1LL;
    }

    return res;
}

void run_case() {
    int N, M, K;
    cin >> N >> M >> K;

    LL m = q_pow(M, MOD - 2LL);

    vector<vector<LL>> dp(K + 1, vector<LL>(N + 1, 0LL));
    dp[0][0] = 1;
    for(int i = 1; i <= K; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 1; k <= M; k++) {
                int to = j + k > N ? 2 * N - j - k : j + k;
                dp[i][to] += dp[i - 1][j] * m % MOD;
                dp[i][to] %= MOD;
            }
        }
    }
    
    LL ans = 0LL;
    for(int i = 0; i <= K; i++) {
        ans += dp[i][N];
        ans %= MOD;
    }
    cout << ans << '\n';
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
