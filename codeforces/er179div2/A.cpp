#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t X;
    std::cin >> X;
    
    std::array<int64_t, 3> a = {};
    std::array<int64_t, 3> t = {X, X, X};
    int ans = 0;
    while(a != t) {
        int64_t x = 2 * a[1] - a[0];
        int64_t y = x + 1;
        if(a[1] >= (a[0] + y) / 2) {
            x = y;
        }
        a[0] = std::min(X, x + a[0]);
        ans += 1;
        std::sort(a.begin(), a.end());
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
