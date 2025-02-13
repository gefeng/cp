#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int64_t MOD = int64_t(1e9) + 7;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int, int64_t> dp;
    dp[0] = 1;
    
    int sum = 0;
    for(int i = 0; i < N; i++) {
        int64_t nxt = 0;
        nxt += 3 * dp[sum] % MOD;
        nxt %= MOD;
        if(dp.find(sum ^ A[i]) != dp.end()) {
            nxt += 2 * dp[sum ^ A[i]] % MOD;
            nxt %= MOD;
        }
        dp[sum] = nxt;
        sum ^= A[i];
    }

    int64_t ans = 0;
    for(auto [_, x] : dp) {
        ans += x;
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
