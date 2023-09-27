#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)1e9 + 7;

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(N == 1) {
        std::cout << 1 << '\n';
        return;
    }

    int64_t ans = 1;
    if(K == 0) {
        for(int i = 1; i < N; i++) {
            if(A[i] % 2 != A[0] % 2) {
                std::cout << 0 << '\n';
                return;
            }
        }

        for(int i = 1; i <= N; i++) {
            ans *= i;
            ans %= MOD;
        } 
    } else {
        int cnt_eve = 0;
        int cnt_odd = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] % 2 == 0) {
                cnt_eve += 1;
            } else {
                cnt_odd += 1;
            }
        }

        if(cnt_eve == 0 || cnt_odd == 0) {
            std::cout << 0 << '\n';
            return;
        }

        if(N % 2 == 0 && cnt_eve != cnt_odd) {
            std::cout << 0 << '\n';
            return;
        }

        if(N % 2 == 1 && std::abs(cnt_eve - cnt_odd) != 1) {
            std::cout << 0 << '\n';
            return;
        }

        if(N % 2 == 0) {
            for(int i = 1; i <= N / 2; i++) {
                ans *= i;
                ans %= MOD;
            }
            ans *= ans;
            ans %= MOD;
            ans *= 2;
            ans %= MOD;
        } else {
            for(int i = 1; i <= N / 2; i++) {
                ans *= i;
                ans %= MOD;
            } 
            ans *= ans * (N / 2 + 1) % MOD;
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
