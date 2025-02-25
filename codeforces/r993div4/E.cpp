#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t K, L1, R1, L2, R2;
    std::cin >> K >> L1 >> R1 >> L2 >> R2;
    
    int64_t ans = 0;
    int64_t max_v = std::max(R1, R2);

    if(L1 <= L2) {
        ans = L2 <= R1 ? std::min(R1, R2) - L2 + 1 : 0;
    } else {
        ans = L1 <= R2 ? std::min(R2, R1) - L1 + 1 : 0;
    }
    int64_t k = 1;
    while(true) {
        if(k <= max_v / K) {
            k *= K;

            int64_t l = k * L1;
            int64_t r = k * R1;
                
            if(l <= L2) {
                ans += L2 <= r ? std::min(r, R2) / k - (L2 - 1) / k : 0;
            } else {
                ans += l <= R2 ? std::min(r, R2) / k - (l - 1) / k : 0;
            }
        } else {
            break;
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
