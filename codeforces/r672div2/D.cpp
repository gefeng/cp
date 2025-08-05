#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

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
    int N, K;
    std::cin >> N >> K;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::vector<int64_t> fact(N + 1, 1);
    std::vector<int64_t> invf(N + 1, 1);
    
    for(int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    std::vector<std::pair<int, int>> events;
    for(int i = 0; i < N; i++) {
        auto [l, r] = A[i];
        events.emplace_back(l, 0);
        events.emplace_back(r + 1, 1);
    }

    std::ranges::sort(events);

    int64_t ans = 0;
    int pre = 0;
    int cnt = 0;
    int n = N << 1;
    for(int i = 0; i < n; ) {
        int j = i;
        while(i < n && events[i].first == events[j].first) {
            i += 1;
        }

        if(cnt >= K && cnt > pre) {
            int64_t x = (fact[cnt] * invf[K] % MOD) * invf[cnt - K] % MOD;
            int64_t y = pre < K ? 0 : (fact[pre] * invf[K] % MOD) * invf[pre - K] % MOD;
            ans += (x - y + MOD) % MOD;
            ans %= MOD;
        }

        pre = cnt;
        for(int k = j; k < i; k++) {
            if(events[k].second == 0) {
                cnt += 1;
            } else {
                cnt -= 1;
                pre -= 1;
            }
        }
    }

    assert(cnt == 0);
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
