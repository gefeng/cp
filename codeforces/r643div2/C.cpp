#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    int64_t ans = 0;
    for(int z = C; z <= D; z++) {
        int64_t a = z + 1 - B;
        // x: [A, a - 1]
        int64_t m = std::min(a - 1, int64_t(B));
        if(m >= A) {
            int64_t l = z + 1 - m;
            int64_t r = z + 1 - A;

            int64_t first = std::max(int64_t(0), C - r + 1);
            int64_t last = std::max(int64_t(0), C - l + 1);
            
            ans += (first + last) * (last - first + 1) / 2;
        }

        // x: [a, B];
        m = std::max(m + 1, int64_t(A));
        if(m <= B) {
            int64_t t = std::max(int64_t(0), B - m + 1);
            ans += (C - B + 1) * t;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
