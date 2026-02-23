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
    int N, H, K;
    std::cin >> N >> H >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t sum = std::accumulate(A.begin(), A.end(), static_cast<int64_t>(0));

    int64_t t = H / sum;
    int64_t ans = t * N + (t - 1) * K;
    
    H %= sum;

    if(H) {
        ans += K;
        int lo = 0;
        int hi = N - 2;
        int res = N - 1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            sum = std::accumulate(A.begin(), A.begin() + mid + 1, static_cast<int64_t>(0));    
            
            int min_v = *std::ranges::min_element(A.begin(), A.begin() + mid + 1);
            int max_v = *std::ranges::max_element(A.begin() + mid + 1, A.end());
            
            if(sum >= H || sum - min_v + max_v >= H) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        ans += res + 1;
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
