#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int64_t lcm(int64_t a, int64_t b) {
    return a * b / gcd(a, b);
}

void run_case() {
    int64_t N;
    std::cin >> N;

    int A1, A2, A3;
    std::cin >> A1 >> A2 >> A3;

    std::array<int, 4> cases = {0, 3, 5, 6};

    auto is_valid = [](int a, int b, int c, int bit, int x) {
        if(a == 1 && bit == 0 && (x & 1)) {
            return false; 
        } 
        if(b == 1 && bit == 0 && (x & 2)) {
            return false;
        }
        if(c == 1 && bit == 0 && (x & 4)) {
            return false;
        }

        return true;
    };
    
    std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int64_t>>>>>> dp(2, 
            std::vector<std::vector<std::vector<std::vector<std::vector<int64_t>>>>>(2, 
                std::vector<std::vector<std::vector<std::vector<int64_t>>>>(2, 
                    std::vector<std::vector<std::vector<int64_t>>>(A1, 
                        std::vector<std::vector<int64_t>>(A2, 
                            std::vector<int64_t>(A3, 0))))));

    dp[1][1][1][0][0][0] = 1;

    for(int bit = 60; bit >= 0; bit--) {
        std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<int64_t>>>>>> ndp(2, 
                std::vector<std::vector<std::vector<std::vector<std::vector<int64_t>>>>>(2, 
                    std::vector<std::vector<std::vector<std::vector<int64_t>>>>(2, 
                        std::vector<std::vector<std::vector<int64_t>>>(A1, 
                            std::vector<std::vector<int64_t>>(A2, 
                                std::vector<int64_t>(A3, 0))))));

        for(int a = 0; a < 2; a++) {
            for(int b = 0; b < 2; b++) {
                for(int c = 0; c < 2; c++) {
                    for(int i = 0; i < A1; i++) {
                        for(int j = 0; j < A2; j++) {
                            for(int k = 0; k < A3; k++) {
                                for(int x : cases) {
                                    int cur_b = (N & (1LL << bit)) ? 1 : 0;
                                    if(is_valid(a, b, c, cur_b, x)) {
                                        int64_t b1 = (x & 1) ? 1 : 0;
                                        int64_t b2 = (x & 2) ? 1 : 0;
                                        int64_t b3 = (x & 4) ? 1 : 0;
                                        int na = a == 0 ? 0 : (b1 < cur_b ? 0 : 1);
                                        int nb = b == 0 ? 0 : (b2 < cur_b ? 0 : 1);
                                        int nc = c == 0 ? 0 : (b3 < cur_b ? 0 : 1);
                                        int ni = (i + (b1 << bit)) % A1;
                                        int nj = (j + (b2 << bit)) % A2;
                                        int nk = (k + (b3 << bit)) % A3;
                                        ndp[na][nb][nc][ni][nj][nk] += dp[a][b][c][i][j][k]; 
                                        ndp[na][nb][nc][ni][nj][nk] %= MOD;
                                    }
                                } 
                            }
                        }
                    }
                }
            }
        }

        std::swap(ndp, dp);
    }

    int64_t ans = 0;
    for(int a = 0; a < 2; a++) {
        for(int b = 0; b < 2; b++) {
            for(int c = 0; c < 2; c++) {
                ans += dp[a][b][c][0][0][0];
                ans %= MOD;
            }
        }
    }

    ans = (ans - N / lcm(A1, A2) + MOD) % MOD;
    ans = (ans - N / lcm(A1, A3) + MOD) % MOD;
    ans = (ans - N / lcm(A2, A3) + MOD) % MOD;
    ans = (ans - 1 + MOD) % MOD;

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
