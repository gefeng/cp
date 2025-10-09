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
    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        psum[i + 1] = psum[i] + A[i];
    }

    std::vector<int64_t> dp(N + 1, 0);
    dp[1] = A[0];

    for(int i = 2; i <= N; i++) {
        int64_t t = dp[i - 1];
        int64_t rem = t * (i - 1) - psum[i - 1];
        
        if(A[i - 1] <= t + rem) {
            dp[i] = t;
        } else {
            dp[i] = t + (A[i - 1] - t - rem + i - 1) / i;
        }
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        
        int lo = 1;
        int hi = N;
        int res = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;

            int64_t t = dp[mid] + (std::max(0LL, psum[N] - dp[mid] * mid) + mid - 1) / mid;
            if(t <= T) {
                res = mid;
                hi = mid - 1; 
            } else {
                lo = mid + 1;
            }
        }

        std::cout << res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
