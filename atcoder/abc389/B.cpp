#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t X;
    std::cin >> X;
    
    int64_t k = 1;
    int64_t f = 1;
    while(f != X) {
        f *= k++;
    }

    std::cout << k - 1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
