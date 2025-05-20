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

    if(B >= A) {
        std::cout << B << '\n';
        return;
    }

    int64_t t = A - B;
    if(D >= C) {
        std::cout << -1 << '\n';
        return;
    }

    int64_t x = t / (C - D);
    
    int64_t ans = C * (x + (t % (C - D) == 0 ? 0 : 1));
    ans += B;
    
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
