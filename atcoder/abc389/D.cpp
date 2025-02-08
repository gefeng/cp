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

    auto check = [&](int x, int y) {
        return (x + 0.5) * (x + 0.5) + (y + 0.5) * (y + 0.5) <= double(R) * R && 
               (x + 0.5) * (x + 0.5) + (y - 0.5) * (y - 0.5) <= double(R) * R;
    };
    
    int64_t ans = 0;
    for(int x = 0; x < R; x++) {
        int lo = 0;
        int hi = R - 1;
        int y = -1;
        
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            if(check(x, mid)) {
                y = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if(y != -1) {
            if(x == 0) {
                ans += (y + 1) * 2;
            } else {
                ans += 2 + y * 4;
            }
        }
    }

    ans -= 1;
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
