#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int64_t MAX = 1e16;

void run_case() {
    int N;
    std::cin >> N;
 
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
 
    int64_t lo = 0;
    int64_t hi = MAX;
    int64_t ans = 0;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
 
        std::vector<int64_t> dp(N + 1, MAX); 
        std::multiset<int64_t> ms;
        int64_t sum = 0;
        int j = 0;
        dp[0] = 0;
        ms.insert(0);
 
        for(int i = 1; i <= N; i++) {
            while(sum > mid) {
                sum -= A[j];
                ms.erase(ms.find(dp[j]));
                j += 1;
            } 
 
            dp[i] = *ms.begin() + A[i - 1];
            ms.insert(dp[i]);
            sum += A[i - 1];
        }
 
        int64_t res = MAX;
        sum = 0;
        for(int i = N; i > 0; i--) {
            if(sum <= mid) {
                res = std::min(res, dp[i]);
                sum += A[i - 1];
            } else {
                break;
            }
        }
 
        if(res <= mid) {
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
