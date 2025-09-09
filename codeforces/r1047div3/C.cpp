#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t A, B;
    std::cin >> A >> B;

    if(A % 2 == 1 && B % 2 == 1) {
        std::cout << A * B + 1 << '\n';
        return;
    }

    if(A % 2 == 0 && B % 2 == 0) {
        std::cout << A * (B >> 1) + 2 << '\n';
        return;
    }

    if(A % 2 == 0 && B % 2 == 1) {
        std::cout << -1 << '\n';
        return;
    }

    if((B / 2) % 2 == 1) {
        std::cout << -1 << '\n';
        return;
    }

    std::cout << (A * B / 2) + 2 << '\n';
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
