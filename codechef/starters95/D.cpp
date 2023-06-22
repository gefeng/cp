#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr LL MOD = (LL)1e9 + 7LL;

LL q_pow(LL x, LL y) {
    LL res = 1LL;
    while(y) {
        if(y & 1LL) {
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
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::string S;
    std::cin >> S;

    std::vector<LL> inv(N + 1, 1LL);
    for(int i = 1; i <= N; i++) {
        inv[i] = q_pow(i, MOD - 2LL);
    }

    std::vector<LL> psum(N + 1, 0LL);
    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + A[i - 1];
        psum[i] %= MOD;
    }
    
    std::vector<std::vector<LL>> dp(N, std::vector<LL>(N, 0LL));
    dp[0][N - 1] = 1LL;

    for(int i = 0; i < K; i++) {
        std::vector<std::vector<LL>> ndp(N, std::vector<LL>(N, 0LL));
        
        if(S[i] == 'L') {
            for(int l = N - 1; l >= 0; l--) {
                std::vector<LL> dif(N + 1, 0LL);
                for(int r = l; r < N; r++) {
                    if(l == r) {
                        ndp[l][r] = dp[l][r];
                        continue;
                    }

                    LL es = dp[l][r] * inv[r - l] % MOD;
                    dif[l] += es;
                    dif[l] %= MOD;
                    dif[r] -= es;
                    dif[r] += MOD;
                    dif[r] %= MOD;
                }

                LL sum = 0LL;
                for(int r = 0; r < N; r++) {
                    sum += dif[r]; 
                    sum %= MOD;
                    ndp[l][r] += sum;
                    ndp[l][r] %= MOD;
                }
            }
        } else {
            for(int r = N - 1; r >= 0; r--) {
                std::vector<LL> dif(N + 1, 0LL);
                for(int l = r; l >= 0; l--) {
                    if(l == r) {
                        ndp[l][r] = dp[l][r];
                        continue;
                    }

                    LL es = dp[l][r] * inv[r - l] % MOD;
                    dif[l + 1] += es;
                    dif[l + 1] %= MOD;
                    dif[r + 1] -= es;
                    dif[r + 1] += MOD;
                    dif[r + 1] %= MOD;
                }

                LL sum = 0LL;
                for(int l = 0; l < N; l++) {
                    sum += dif[l]; 
                    sum %= MOD;
                    ndp[l][r] += sum;
                    ndp[l][r] %= MOD;
                }
            }
        }
        std::swap(dp, ndp);
    }

    LL ans = 0LL;
    for(int l = 0; l < N; l++) {
        for(int r = l; r < N; r++) {
            LL sum = (psum[r + 1] - psum[l] + MOD) % MOD; 
            ans += sum * dp[l][r] % MOD;
            ans %= MOD;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
