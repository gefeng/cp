#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(1e9) + 7;

void run_case() {
    std::string S;
    std::cin >> S;

    int n = S.size(); 
    
    std::vector<int64_t> p_10(n + 1, 1);
    for(int i = 1; i <= n; i++) {
        p_10[i] = p_10[i - 1] * 10 % MOD;
    }

    std::vector<int64_t> now(10, 0);
    for(int i = 0; i < 10; i++) {
        now[i] = i;
    }
    int64_t ans = now[S.back() - '0'];
    for(int i = n - 2; i >= 0; i--) {
        std::vector<int64_t> nxt(10, 0);
        for(int d = 0; d < 10; d++) {
            int64_t x = d * p_10[n - 1 - i] % MOD;
            x += (d * p_10[n - 2 - i] % MOD) * (n - 2 - i) % MOD;
            x %= MOD;

            x += now[d];
            x %= MOD;

            nxt[d] = x;
        }

        now = std::move(nxt);

        ans += now[S[i] - '0'];
        ans %= MOD;
    }

    for(int i = n - 1; i >= 0; i--) {
        ans += ((static_cast<int64_t>(i + 1) * i / 2) % MOD) * ((S[i] - '0') * p_10[n - 1 - i] % MOD) % MOD;
        ans %= MOD;
    }

    for(int i = 0; i < n; i++) {
        ans -= (S[i] - '0') * p_10[n - 1 - i] % MOD;
        ans += MOD;
        ans %= MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
