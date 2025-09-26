#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9);

void run_case() {
    int L1, R1, L2, R2;
    std::cin >> L1 >> R1 >> L2 >> R2;
    
    int ans = INF;
    for(int i = L1; i <= R1; i++) {
        if(i >= L2 && i <= R2) {
            ans = std::min(ans, i);
        } else {
            if(i < L2) {
                if(L2 >= L1 && L2 <= R1) {
                    ans = std::min(ans, L2);
                } else {
                    ans = std::min(ans, i + L2);
                }
            } else {
                ans = std::min(ans, i + L2);
            }
        }
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
