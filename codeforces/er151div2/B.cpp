#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    std::array<LL, 6> A = {};

    for(int i = 0; i < 6; i++) {
        std::cin >> A[i];
    } 

    LL ba_x = A[2] - A[0];
    LL ba_y = A[3] - A[1];
    LL ca_x = A[4] - A[0];
    LL ca_y = A[5] - A[1];

    bool same_x = ba_x * ca_x >= 0;
    bool same_y = ba_y * ca_y >= 0;

    LL ans = 0LL;
    if(same_x && same_y) {
        ans = std::min(std::abs(ba_x), std::abs(ca_x)) + std::min(std::abs(ba_y), std::abs(ca_y));
    } else if(!same_x && !same_y) {
        ans = 0LL;
    } else if(same_x) {
        ans = std::min(std::abs(ba_x), std::abs(ca_x));
    } else {
        ans = std::min(std::abs(ba_y), std::abs(ca_y));
    }

    std::cout << ans + 1 << '\n';
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
