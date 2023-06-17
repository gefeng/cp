#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int W, L;
    std::cin >> W >> L;

    if(W % 2 == 1 && L % 2 == 1) {
        std::cout << "NO" << '\n';
    } else {
        std::cout << "YES" << '\n';
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
