#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(998244353);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int64_t> ans(N + 1, 0);
    std::vector<int64_t> p_10(N + 1, 1);
    
    for(int i = 1; i <= N; i++) {
        p_10[i] = p_10[i - 1] * 10 % MOD;
    }

    for(int d = 0; d <= 9; d++) {
        for(int len = 1; len <= N; len++) {
            if(len == N) {
                ans[len] += 1;
                ans[len] %= MOD;
            } else {
                int pos = N - len - 1;
                int64_t cnt = 0;
                if(len < N - 1) {
                    cnt += (pos * 81 % MOD) * p_10[N - len - 2] % MOD;
                    cnt %= MOD;
                }
                
                cnt += 18 * p_10[N - len - 1] % MOD;
                cnt %= MOD;
                ans[len] += cnt;
                ans[len] %= MOD;
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        std::cout << ans[i] << " \n"[i == N];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
