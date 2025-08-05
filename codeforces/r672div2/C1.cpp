#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::vector<int64_t> dp(2, 0);
    for(int i = 0; i < N; i++) {
        std::vector<int64_t> n_dp(dp);

        n_dp[0] = std::max(n_dp[0], dp[1] + A[i]);
        n_dp[1] = std::max(n_dp[1], dp[0] - A[i]);
        
        dp = std::move(n_dp);
    }

    std::cout << std::max(dp[0], dp[1]) << '\n';
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
