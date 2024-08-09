#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::array<int, 3> A = {};
    for(int i = 0; i < 3; i++) {
        std::cin >> A[i];
    }

    int a = A[0] + A[2];
    int b = A[1] * 2;
    
    if(a == b || std::abs(a - b) % 3 == 0) {
        std::cout << 0 << '\n';
    } else {
        std::cout << 1 << '\n';
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
