#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int L1, R1, L2, R2;
    std::cin >> L1 >> R1 >> L2 >> R2;

    if(L1 > L2) {
        std::swap(L1, L2);
        std::swap(R1, R2);
    }
    
    int ans = 0;
    if(L2 >= L1 && L2 <= R1) {
        int l = std::max(L1, L2);
        int r = std::min(R1, R2);
        ans = r - l;
        if(L1 != L2) {
            ans += 1;
        }
        if(R1 != R2) {
            ans += 1;
        }
    } else {
        ans = 1;
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
