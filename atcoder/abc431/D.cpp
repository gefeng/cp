#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    std::vector<int> B(N);
    std::vector<int> C(N);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i] >> C[i];
    }

    int max_s = std::accumulate(A.begin(), A.end(), 0);

    std::vector<int64_t> dp(max_s + 1, -1);
    dp[0] = 0;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        std::vector<int64_t> ndp(max_s + 1, -1);
        
        for(int j = 0; j <= max_s; j++) {
            if(j + A[i] <= max_s && dp[j] != -1) {
                ndp[j + A[i]] = std::max(ndp[j + A[i]], dp[j] + B[i]);
            }
            if(dp[j] != -1 && sum - j + A[i] <= max_s) {
                ndp[j] = std::max(ndp[j], dp[j] + C[i]);
            }
        }

        dp = std::move(ndp);
        sum += A[i];
    }

    int64_t ans = 0;
    for(int i = 0; i <= max_s; i++) {
        if(sum - i >= i) {
            ans = std::max(ans, dp[i]);
        }
    }    

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
