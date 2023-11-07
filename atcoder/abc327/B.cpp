#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t B;
    std::cin >> B;

    for(int64_t i = 1; i <= 15; i++) {
        int64_t x = i;
        for(int j = 2; j <= i; j++) {
            x *= i;
        }
        if(B == x) {
            std::cout << i << '\n';
            return;
        }
    } 

    std::cout << -1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
