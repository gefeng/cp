#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int S_X, S_Y, T_X, T_Y;
    std::cin >> S_X >> S_Y >> T_X >> T_Y;

    int64_t w = T_X - S_X + 1;
    int64_t h = T_Y - S_Y + 1;

    int64_t d = w + h - 1;
    int64_t l = std::min(w, h) - 1;
    
    int64_t ans = (l - 1) * l;
    ans += l * (d - l * 2);
    ans += 1;

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
