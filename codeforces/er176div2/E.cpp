#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 30;
constexpr int64_t MOD = int64_t(998244353);

int64_t q_pow(int64_t x, int64_t y) {
    int64_t res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= MOD;
        } 
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

void run_case() {
    int64_t N, M, A, B;
    std::cin >> N >> M >> A >> B;
    
    int64_t ans = 0;
    
    ans += ((A + 1) * ((B * (B + 1) / 2) % MOD) % MOD) * ((q_pow(2, M) - 2 + MOD) % MOD) % MOD;
    ans %= MOD;
    ans += ((B + 1) * ((A * (A + 1) / 2) % MOD) % MOD) * ((q_pow(2, N) - 2 + MOD) % MOD) % MOD;
    ans %= MOD;

    ans += (A + 1) * (B + 1) % MOD;
    ans %= MOD;

    // a < b <= A
    // x < y <= B
    std::vector<std::vector<int64_t>> dp(MAX + 1, std::vector<int64_t>(1 << 4, 0));
    dp[MAX][0] = 1;
    
    for(int i = MAX - 1; i >= 0; i--) {
        for(int mask = 0; mask < (1 << 4); mask++) {
            for(int a = 0; a < 2; a++) {
                for(int b = 0; b < 2; b++) {
                    for(int x = 0; x < 2; x++) {
                        for(int y = 0; y < 2; y++) {
                            int n_mask = 0;
                            if(mask & 1) {
                                n_mask |= 1; 
                            } else {
                                if(a > b) {
                                    continue;
                                }
                                if(a < b) {
                                    n_mask |= 1; 
                                }
                            }

                            if(mask & 2) {
                                n_mask |= 2;
                            } else {
                                int bit_A = A & (1 << i) ? 1 : 0;
                                if(b > bit_A) {
                                    continue;
                                }
                                if(b < bit_A) {
                                    n_mask |= 2;
                                }
                            }

                            if(mask & 4) {
                                n_mask |= 4;
                            } else {
                                if(x > y) {
                                    continue;
                                }
                                if(x < y) {
                                    n_mask |= 4;
                                }
                            }

                            if(mask & 8) {
                                n_mask |= 8;
                            } else {
                                int bit_B = B & (1 << i) ? 1 : 0;
                                if(y > bit_B) {
                                    continue;
                                }
                                if(y < bit_B) {
                                    n_mask |= 8;
                                }
                            }
                            if((a ^ b) == (x ^ y)) {
                                dp[i][n_mask] += dp[i + 1][mask];
                                dp[i][n_mask] %= MOD;
                            }
                        }
                    }
                }
            }
        }
    }

    int64_t sum = 0;
    for(int i = 0; i < (1 << 4); i++) {
        if((i & 1) && (i & 4)) {
            sum += dp[0][i];
            sum %= MOD;
        }
    }

    std::cout << sum << ' ' << dp[0][15] << '\n';

    sum *= (q_pow(2, N) - 2 + MOD) % MOD;
    sum %= MOD;
    
    sum *= (q_pow(2, M) - 2 + MOD) % MOD;
    sum %= MOD;

    ans += sum;
    ans %= MOD;
    
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
