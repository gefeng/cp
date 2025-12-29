#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::array<int, 2> A = {};
    for(int i = 0; i < 2; i++) {
        std::cin >> A[i];
    }

    auto count = [&](int flip) {
        int now = 1;
        int t = flip;
        std::array<int, 2> a(A);
        int res = 0;
        while(a[t] >= now) {
            a[t] -= now;
            t ^= 1;
            now *= 2;
            res += 1;
        }

        return res;
    };

    std::cout << std::max(count(0), count(1)) << '\n';
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
