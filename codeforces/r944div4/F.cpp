#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int R;
    std::cin >> R;

    int64_t ans = 0;
    for(int x = -R; x <= R; x++) {
        int64_t a = (int64_t)(R - x) * (R + x);
        int64_t b = (int64_t)(R - x + 1) * (R + x + 1);
        
        int64_t ra = (int64_t)sqrt(a);
        int64_t rb = (int64_t)sqrt(b);

        if(ra * ra == a && rb * rb == b) {
            ans += (rb - ra) * 2;
            if(ra == 0) {
                ans -= 1;
            }
        } else if(ra * ra == a) {
            ans += (rb - ra + 1) * 2;
            if(ra == 0) {
                ans -= 1;
            }
        } else if(rb * rb == b) {
            ans += std::max((int64_t)0, (rb - ra - 1)) * 2;
        } else {
            ans += (rb - ra) * 2;
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
