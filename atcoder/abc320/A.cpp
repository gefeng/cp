#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B;
    std::cin >> A >> B;

    int64_t x = 1;
    int64_t y = 1;
    for(int i = 0; i < B; i++) {
        x *= A; 
    }

    for(int i = 0; i < A; i++) {
        y *= B;
    }

    std::cout << x + y << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
