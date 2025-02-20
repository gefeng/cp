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
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> dp(4, 0);    
    for(int i = 0; i < N; i++) {
        std::vector<int64_t> ndp(dp);
        
        if(A[i] == 1) {
            ndp[1] += 1;
            ndp[1] %= MOD;
        }
        if(A[i] == 2) {
            ndp[2] += (dp[1] + dp[2]) % MOD;
            ndp[2] %= MOD;
        }
        if(A[i] == 3) {
            ndp[3] += dp[2];
            ndp[3] %= MOD;
        }
        std::swap(dp, ndp);
    }

    std::cout << dp[3] << '\n';
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
