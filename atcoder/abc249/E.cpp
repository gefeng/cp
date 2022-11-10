#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

int f(int x) {
    if(x > 0 && x < 10) {
        return 2;
    }
    if(x > 9 && x < 100) {
        return 3;
    }
    if(x > 99 && x < 1000) {
        return 4;
    }

    return 5;
}

void run_case() {
    int N;
    cin >> N;

    LL MOD;
    cin >> MOD;

    vector<vector<LL>> dp(N + 1, vector<LL>(N + 1, 0LL));
    vector<vector<LL>> psum(N + 1, vector<LL>(N + 1, 0LL)); // row sum
    
    for(int i = 1; i <= N; i++) {
        dp[i][f(i)] = 26LL;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int l = 1;
            int r = 9;
            for(int k = 2; k <= 5; k++) {
                int p_j = j - k;
                if(p_j >= 0 && l <= min(r, i - 1)) {
                    dp[i][j] += ((psum[i - l][p_j] - psum[i - min(r, i - 1) - 1][p_j] + MOD) % MOD) * 25LL;
                    dp[i][j] %= MOD;
                }
                l = r + 1;
                r = l * 10 - 1;
            } 

            psum[i][j] = psum[i - 1][j] + dp[i][j];
            psum[i][j] %= MOD;
        }
    }

    LL ans = 0LL;
    for(int i = 2; i < N; i++) {
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
