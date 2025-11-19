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

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);

    std::vector<int> a;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }
        a.push_back(i - j);
    }

    int n = a.size();
    std::ranges::sort(a);
    
    std::vector<int64_t> dp(N + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        std::vector<int64_t> ndp(dp);
        for(int j = 0; j <= N - a[i]; j++) {
            ndp[j + a[i]] += dp[j] * a[i] % MOD;
            ndp[j + a[i]] %= MOD;
        }
        dp = std::move(ndp);
    }

    int64_t ans = 0;
    for(int i = a.back(); i <= N; i++) {
        ans += dp[i];
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
