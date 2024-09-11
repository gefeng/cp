#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = int64_t(2e18);

void run_case() {
    int64_t A, B, K;
    std::cin >> A >> B >> K;

    if(K == 1) {
        std::cout << 0 << '\n';
        return;
    }
    
    int64_t ans = 0;
    if(A == B) {
        ans = K / 2 * A; 
    } else if(A < B) {
        if(K % 2 == 0) {
            ans = A + (K / 2 - 1) * B;
        } else {
            ans = K / 2 * B;
        }
    } else {
        int64_t lo = 1;
        int64_t hi = MAX;
        while(lo <= hi) {
            int64_t mid = (lo + hi) >> 1;
            
            int64_t cnt = 1;
            int64_t k = mid >= A ? (mid - A) / B : -1;

            cnt += k + 1;
            k = mid / B;
            cnt += k;
            
            if(cnt >= K) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
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
