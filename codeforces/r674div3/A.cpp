#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X;
    std::cin >> N >> X;
    
    if(N <= 2) {
        std::cout << 1 << '\n';
        return;
    }

    N -= 2;
    std::cout << 1 + ((N / X) + (N % X == 0 ? 0 : 1)) << '\n';
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
