#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X;
    std::cin >> N >> X;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + A[i - 1];
    }

    auto bs = [&](int st) {
        int lo = st;
        int hi = N - 1;
        int res = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            if(psum[mid + 1] - psum[st] > X) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return res;
    };

    std::vector<int64_t> dp(N, 0);
    int64_t ans = 0;
    for(int i = N - 1; i >= 0; i--) {
        int j = bs(i);
        
        if(j == -1) {
            dp[i] = N - i;
        } else {
            dp[i] = j - i;
            if(j + 1 < N) {
                dp[i] += dp[j + 1];
            }
        }
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
