#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int P;
    std::cin >> P;

    if(P == 5) {
        std::cout << 2 << ' ' << 4 << '\n'; 
    } else {
        std::cout << 2 << ' ' << (P - 1) / 2 << '\n';
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
