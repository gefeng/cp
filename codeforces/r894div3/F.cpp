#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = (int)1e6;

void run_case() {
    int W, F, N;
    std::cin >> W >> F >> N;

    std::vector<int> A(N);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    std::vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for(int i = 0, k = 0; i < N; i++) {
        std::vector<int> ndp(sum + 1, 0);
        k += A[i];
        for(int j = 0; j <= k; j++) {
            ndp[j] = dp[j]; 
            
            if(j - A[i] >= 0) {
                ndp[j] = ndp[j] || dp[j - A[i]];
            }
        }

        std::swap(dp, ndp);
    }

    int lo = 1;
    int hi = MAX;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        int w = std::min((int64_t)sum, (int64_t)W * mid);
        int f = std::min((int64_t)sum, (int64_t)F * mid);

        bool ok = false;
        for(int i = 0; i <= w; i++) {
            if(dp[i] && sum - i <= f) {
                ok = true;
                break;
            }
        } 

        if(ok) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
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
