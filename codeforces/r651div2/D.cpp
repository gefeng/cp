#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(1e9);
constexpr int INF = int(2e9);

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int lo = 1;
    int hi = MAX;
    int res = MAX;
    int ans = MAX;

    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
    
        std::vector<int> dp(2, -INF);
        dp[0] = 0; 
        
        for(int i = 0; i < N; i++) {
            std::vector<int> n_dp(dp);

            if(A[i] <= mid) {
                n_dp[1] = std::max(n_dp[1], 1);
                for(int j = 0; j < 2; j++) {
                    if(dp[j] != -INF) {
                        n_dp[j ^ 1] = std::max(n_dp[j ^ 1], dp[j] + 1);
                    }
                }
            } else {
                if(dp[1] != -INF) {
                    n_dp[0] = std::max(n_dp[0], dp[1] + 1);
                }
            }

            dp = std::move(n_dp);
        }

        if(dp[K % 2] >= K) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    ans = std::min(ans, res);

    lo = 1;
    hi = MAX;
    res = MAX;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;

        std::vector<int> dp(2, -INF);
        dp[0] = 0; 
        
        for(int i = 0; i < N; i++) {
            std::vector<int> n_dp(dp);
            
            n_dp[1] = std::max(n_dp[1], 1);

            if(A[i] <= mid) {
                for(int j = 0; j < 2; j++) {
                    if(dp[j] != -INF) {
                        n_dp[j ^ 1] = std::max(n_dp[j ^ 1], dp[j] + 1);
                    }
                }
            } else {
                if(dp[0] != -INF) {
                    n_dp[1] = std::max(n_dp[1], dp[0] + 1);
                }
            }

            dp = std::move(n_dp);
        }
        
        if(dp[K % 2] >= K) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    ans = std::min(ans, res);

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
