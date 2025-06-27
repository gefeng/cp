#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B, C, R;
    std::cin >> A >> B >> C >> R;

    int l = C - R;
    int r = C + R;


    if(A < B) {
        if(B < l || A > r) {
            std::cout << std::abs(B - A) << '\n';
            return;
        }
        std::cout << B - A - std::min(B, r) + std::max(A, l) << '\n';
    } else {
        if(A < l || B > r) {
            std::cout << std::abs(B - A) << '\n';
            return;
        }
        std::cout << A - B - std::min(A, r) + std::max(B, l) << '\n';
    }
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
