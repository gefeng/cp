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
    int64_t M;
    std::cin >> N >> M;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> p2(N + 1, 1);
    for(int i = 1; i <= N; i++) {
        p2[i] = p2[i - 1] * 2 % MOD;
    }

    std::vector<std::pair<int64_t, int>> pf;
    int64_t m = M;
    for(int64_t f = 2; f * f <= m; f++) {
        if(m % f == 0) {
            int cnt = 0;
            while(m % f == 0) {
                m /= f;
                cnt += 1;
            }
            pf.emplace_back(f, cnt);
        }
    }
    if(m > 1) {
        pf.emplace_back(m, 1);
    }

    std::sort(pf.begin(), pf.end());

    int n = pf.size();
    std::vector<int> cnt_mask((1 << n), 0);
    std::vector<int> all;
    for(int i = 0; i < N; i++) {
        int64_t x = A[i];
        if(M % x != 0) {
            continue;
        }

        int mask = 0;
        for(int j = 0; j < n; j++) {
            auto [v, f] = pf[j];
            int cnt = 0;
            while(x % v == 0) {
                x /= v;
                cnt += 1;
            }
            if(cnt == f) {
                mask |= 1 << j;
            }
        }

        all.push_back(mask);
        cnt_mask[mask] += 1;
    }
    
    std::sort(all.begin(), all.end());
    all.erase(std::unique(all.begin(), all.end()), all.end());

    int size = all.size();
    std::vector<std::vector<int64_t>> dp(size + 1, std::vector<int64_t>(1 << n, 0));
    dp[0][0] = 1;
    for(int i = 0; i < size; i++) {
        int cur = all[i];
        for(int mask = 0; mask < (1 << n); mask++) {
            dp[i + 1][mask] += dp[i][mask];
            dp[i + 1][mask] %= MOD;

            dp[i + 1][mask | cur] += dp[i][mask] * ((p2[cnt_mask[cur]] - 1 + MOD) % MOD) % MOD;
            dp[i + 1][mask | cur] %= MOD;
        }
    }

    std::cout << dp[size][(1 << n) - 1] + (M == 1 ? -1 : 0) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
