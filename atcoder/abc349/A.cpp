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

    int sum = 0;
    for(int i = 0; i < N - 1; i++) {
        int X;
        std::cin >> X;
        sum += X;
    }

    std::cout << 0 - sum << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
