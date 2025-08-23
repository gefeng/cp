#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    int64_t ans = 0;
    while(true) {
        if(N < 3) {
            ans += 3 * N; 
            break;
        }

        int64_t p3 = 1;
        int64_t x = 0;
        while(p3 * 3 <= N) {
            p3 *= 3;
            x += 1;
        }

        ans += p3 * 3 + x * (p3 / 3);
        N -= p3;
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
