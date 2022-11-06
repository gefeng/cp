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
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<LL>> dp(N + 1, vector<LL>(M + 1, 0LL));
    vector<LL> psum(M + 1, 0LL);
    for(int i = 1; i <= M; i++) {
        dp[1][i] = 1LL;
        psum[i] = psum[i - 1] + dp[1][i];
        psum[i] %= MOD;
    }

    for(int i = 2; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            // [1, j-K]
            if(j - K >= 1) {
                dp[i][j] += psum[j - K];
                dp[i][j] %= MOD;
            }
            // [j+K, M]
            if(j + K <= M) {
                dp[i][j] += psum[M] - psum[j + K - 1] + MOD;
                dp[i][j] %= MOD;
            }

            if(K == 0) {
                dp[i][j] -= dp[i - 1][j];
                dp[i][j] += MOD;
                dp[i][j] %= MOD;
            }
        }

        for(int j = 1; j <= M; j++) {
            psum[j] = psum[j - 1] + dp[i][j];
            psum[j] %= MOD;
        }
    }

    LL ans = 0LL;
    for(int i = 1; i <= M; i++) {
        ans += dp[N][i];
        ans %= MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
