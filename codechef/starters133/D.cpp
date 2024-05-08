#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;

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
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> psum_zero(N + 1, 0);
    std::vector<int> nxt_dup(N, N);
    std::vector<int> pre_pos(M + 1, N); 
    std::vector<int64_t> fact(std::max(N, M) + 1, 1);
    std::vector<int64_t> invf(std::max(N, M) + 1, 1);
    int k = 0;
    int64_t ans = 0;

    for(int i = 0; i < N; i++) {
        psum_zero[i + 1] = psum_zero[i] + (A[i] == 0 ? 1 : 0);
    }

    for(int i = N - 1; i >= 0; i--) {
        if(i < N - 1) {
            if(A[i] != 0) {
                nxt_dup[i] = std::min(pre_pos[A[i]], nxt_dup[i + 1]);
            } else {
                nxt_dup[i] = nxt_dup[i + 1];
            }
        }

        if(A[i] != 0) {
            if(pre_pos[A[i]] == N) {
                k += 1;
            }
            pre_pos[A[i]] = i;
        }
    }

    for(int i = 1; i <= std::max(N, M); i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }
    
    for(int i = std::max(1, k); i <= std::min(N, M); i++) {
        int64_t c = (fact[M - k] * invf[i - k] % MOD) * invf[M - i] % MOD;

        int64_t x = 1;
        for(int j = 0; j < N; j += i) {
            int size = std::min(j + i, N) - j;
            if(nxt_dup[j] < std::min(j + i, N)) {
                x = 0;
                break;
            }

            int cnt_zero = psum_zero[std::min(j + i, N)] - psum_zero[j];
            if(size == i) {
                x *= fact[cnt_zero];
                x %= MOD;
            } else {
                x *= fact[i - size + cnt_zero] * invf[i - size] % MOD;  
                x %= MOD;
            }
        }

        ans += x * c % MOD;
        ans %= MOD;
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
