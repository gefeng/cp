#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(998244353);

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
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::vector<int64_t> ans(N * 2, 0);
    int max = -1;
    for(int i = 0; i < N; i++) {
        auto [a, b] = A[i];
        max = std::max(max, a);
        max = std::max(max, b);
    }

    std::vector<int64_t> fact(N * 2 + 1, 1);
    std::vector<int64_t> invf(N * 2 + 1, 1);

    for(int i = 1; i <= N * 2; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    int c1 = 0; // (max1, max1)
    int c2 = 0; // (max1, max2)
    int c3 = 0; // (max1, < max2)
    for(auto [a, b] : A) {
        if(a == max && b == max) {
            c1++;
        } else if(a == max || b == max) {
            c2++;
        }
    }

    int64_t p1 = 0;
    int64_t p2 = 0;
    int64_t inv2 = q_pow(2, MOD - 2);
    for(int i = 0; i <= c2; i++) {
        p1 += ((fact[c2] * invf[i] % MOD) * invf[c2 - i] % MOD) * q_pow(c1 + i, MOD - 2) % MOD;
        p1 %= MOD;
    }
    p1 *= q_pow(inv2, c2);
    p1 %= MOD;

    if(c2) {
        for(int i = 0; i <= c2 - 1; i++) {
            p2 += ((fact[c2 - 1] * invf[i] % MOD) * invf[c2 - 1 - i] % MOD) * q_pow(c1 + 1 + i, MOD - 2) % MOD;
            p2 %= MOD;
        }
        p2 *= q_pow(inv2, c2 - 1);
        p2 %= MOD;
    }

    for(int i = 0; i < N; i++) {
        auto [a, b] = A[i];
        if(a == max && b == max) {
            ans[i * 2] = p1 * inv2 % MOD;
            ans[i * 2 + 1] = p1 * inv2 % MOD;
        } else if(a == max) {
            ans[i * 2] = p2 * inv2 % MOD;
        } else if(b == max) {
            ans[i * 2 + 1] = p2 * inv2 % MOD;
        }
    }
    //std::cout << ans[3] * inv2 % MOD << ' ' << ans[7] << ' ' << 3 * q_pow(8, MOD - 2) % MOD << '\n';

    if(c1 == 0) {
        c1 = 0; // (max - 1, max - 1)
        c2 = 0; // (max, max - 1)
        c3 = 0; // (max, < max - 1)
        int c4 = 0; // (max - 1, < max - 1)
        
        int s = 0; // count match with at least one max
        for(int i = 0; i < N; i++) {
            auto [a, b] = A[i];
            if(a == max || b == max) {
                s++;
            }

            if(a == max - 1 && b == max - 1) {
                c1++;
            } else if((a == max && b == max - 1) || (a == max - 1 && b == max)) {
                c2++;
            } else if((a == max && b < max - 1) || (a < max - 1 && b == max)) {
                c3++;
            } else if((a == max - 1 && b < max - 1) || (a < max - 1 && b == max - 1)) {
                c4++;
            }
        }

        int m = c1 + 2 * c2 + c3;

        int64_t p1 = 0;
        int64_t p2 = 0;
        for(int i = 0; i <= c4; i++) {
            p1 += ((fact[c4] * invf[i] % MOD) * invf[c4 - i] % MOD) * q_pow(m + i, MOD - 2) % MOD;
            p1 %= MOD;
        }
        p1 *= q_pow(inv2, c4);
        p1 %= MOD;

        if(c4) {
            for(int i = 0; i <= c4 - 1; i++) {
                p2 += ((fact[c4 - 1] * invf[i] % MOD) * invf[c4 - 1 - i] % MOD) * q_pow(m + 1 + i, MOD - 2) % MOD;
                p2 %= MOD;
            }
            p2 *= q_pow(inv2, c4 - 1);
            p2 %= MOD;
        }
        
        p1 *= q_pow(inv2, s);
        p1 %= MOD;
        p2 *= q_pow(inv2, s);
        p2 %= MOD;

        for(int i = 0; i < N; i++) {
            auto [a, b] = A[i];
            if(a == max - 1 && b == max - 1) {
                ans[i * 2] += p1 * inv2 % MOD;
                ans[i * 2] %= MOD;
                ans[i * 2 + 1] += p1 * inv2 % MOD;
                ans[i * 2 + 1] %= MOD;
            } else if((a == max && b == max - 1) || (a == max - 1 && b == max)) {
                ans[i * 2] += p1;
                ans[i * 2] %= MOD;
                ans[i * 2 + 1] += p1;
                ans[i * 2 + 1] %= MOD;
            } else if((a == max && b < max - 1) || (a < max - 1 && b == max)) {
                if(a == max) {
                    ans[i * 2] += p1;
                    ans[i * 2] %= MOD;
                } else {
                    ans[i * 2 + 1] += p1;
                    ans[i * 2 + 1] %= MOD;
                }
            } else if((a == max - 1 && b < max - 1) || (a < max - 1 && b == max - 1)) {
                if(a == max - 1) {
                    ans[i * 2] += p2 * inv2 % MOD;
                    ans[i * 2] %= MOD;
                } else {
                    ans[i * 2 + 1] += p2 * inv2 % MOD;
                    ans[i * 2 + 1] %= MOD;
                }
            }
        }
    }

    for(int i = 0; i < N * 2; i++) {
        std::cout << ans[i] << " \n"[i == N * 2 - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
