#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int R, B, D;
    std::cin >> R >> B >> D;
    
    int x = std::min(R, B);
    R -= x;
    B -= x;
    
    int y = 0;
    if(R) {
        y = R / x + (R % x == 0 ? 0 : 1);
    } else {
        y = B / x + (B % x == 0 ? 0 : 1);
    }

    std::cout << (y <= D ? "Yes" : "No") << '\n';
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
