#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int P, Q;
    std::cin >> P >> Q;

    int t = P + 2 * Q;
    int st = sqrt(t);
    
    for(int n = 1; n <= st; n++) {
        if((t - n) % (2 * n + 1) == 0) {
            int m = (t - n) / (2 * n + 1);
            if(P >= std::abs(n - m)) {
                std::cout << n << ' ' << m << '\n';
                return;
            }
        }
    }

    std::cout << -1 << '\n';
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
