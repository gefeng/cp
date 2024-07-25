#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> dp(N, 0);
    for(int i = 1; i < N; i++) {
        if(A[i] >= A[i - 1]) {
            if(A[i - 1] == 1) {
                continue;
            }
            int64_t x = A[i - 1];
            int64_t cnt = 0;
            while(x < A[i]) {
                x *= x;
                cnt += 1;
            }
            if(x == A[i]) {
                dp[i] = std::max(int64_t(0), dp[i - 1] - cnt);
            } else {
                dp[i] = std::max(int64_t(0), dp[i - 1] - cnt + 1);
            }
        } else {
            if(A[i] == 1) {
                std::cout << -1 << '\n'; 
                return;
            }
            int64_t x = A[i];
            int cnt = 0;
            while(x < A[i - 1]) {
                x *= x; 
                cnt += 1;
            }
            dp[i] = dp[i - 1] + cnt;
        }
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        ans += dp[i];
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
