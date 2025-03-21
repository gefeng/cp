#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    double X;
    std::cin >> X;

    if(X >= 38.0) {
        std::cout << 1 << '\n';
        return;
    }
    
    if(X >= 37.5 && X < 38.0) {
        std::cout << 2 << '\n';
        return;
    }

    std::cout << 3 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
