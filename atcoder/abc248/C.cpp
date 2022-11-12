#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = 998244353;

void run_case() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<LL>> dp(N + 1, vector<LL>(K + 1, 0LL));
    dp[0][0] = 1LL;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            for(int k = 1; k <= M; k++) {
                if(j - k >= 0) {
                    dp[i][j] += dp[i - 1][j - k];
                    dp[i][j] %= MOD;
                }
            }
        }
    }

    LL ans = 0LL;
    for(int i = 1; i <= K; i++) {
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
