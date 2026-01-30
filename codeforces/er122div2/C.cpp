#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t HC, DC, HM, DM, K, W, A;
    std::cin >> HC >> DC >> HM >> DM >> K >> W >> A;

    for(int64_t i = 0; i <= K; i++) {
        int64_t d = DC + i * W;
        int64_t h = HC + (K - i) * A;
        if((HM + d - 1) / d <= (h + DM - 1) / DM) {
            std::cout << "YES" << '\n';
            return;
        }
    }

    std::cout << "NO" << '\n';
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
