#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, L, R;
    std::cin >> N >> L >> R;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + A[i];
    }

    auto bs = [&](int i) {
        int lo = 0;
        int hi = i;
        int res = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            if(psum[i + 1] - psum[mid] >= L) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if(res != -1) {
            if(psum[i + 1] - psum[res] > R) {
                res = -1;
            }
        }
        return res;
    };

    std::vector<int> dp(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1];
        int j = bs(i - 1);
        if(j != -1) {
            dp[i] = std::max(dp[i], dp[j] + 1); 
        }
    }

    std::cout << dp[N] << '\n';
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
