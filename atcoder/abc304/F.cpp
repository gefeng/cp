#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<int> factors;
    for(int f = 1; f * f <= N; f++) {
        if(N % f == 0) {
            factors.push_back(f);
            if(N / f != N && N / f != f) {
                factors.push_back(N / f);
            }
        }
    }

    std::vector<int64_t> p_2(N + 1, 1);
    for(int i = 1; i <= N; i++) {
        p_2[i] = p_2[i - 1] * 2 % MOD; 
    }

    std::sort(factors.begin(), factors.end());

    int64_t ans = 0;
    int m = factors.size();
    std::vector<int64_t> dp(m, 0);
    for(int k = 0; k < m; k++) {
        int f = factors[k];
        std::vector<int> free(f, 1);
        for(int i = 0; i < N; i += f) {
            for(int j = 0; j < f; j++) {
                if(S[i + j] == '.') {
                    free[(i + j) % f] = 0;
                } 
            } 
        }

        int cnt = 0;
        for(int i = 0; i < f; i++) {
            if(free[i]) {
                cnt += 1;
            }
        }

        int64_t x = p_2[cnt];
        for(int i = 0; i < k; i++) {
            if(f % factors[i] == 0) {
                x -= dp[i];
                x += MOD;
                x %= MOD;
            }
        }
        
        ans += x;
        ans %= MOD;
        dp[k] = x;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
