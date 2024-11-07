#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t H, K;
    std::cin >> H >> K;

    int64_t x = 1;
    int ans = 0;
    while(x * 2 <= K) {
        x <<= 1;
        ans += 1;
    }

    while(H != 1) {
        int64_t max_f = 1;
        for(int64_t f = 2; f * f <= H; f++) {
            if(H % f == 0) {
                max_f = std::max(max_f, std::max(f, H / f)); 
            }
        }
        ans += 1;
        H = max_f;
    }
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
