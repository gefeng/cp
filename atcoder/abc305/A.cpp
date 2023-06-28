#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    int ub = (N + 5 - 1) / 5 * 5;
    int lb = N / 5 * 5;
    
    if(ub - N < N - lb) {
        std::cout << ub << '\n';
    } else {
        std::cout << lb << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
