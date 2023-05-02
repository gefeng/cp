#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    LL N, K;
    std::cin >> N >> K;

    if(N > K) {
        N -= (N / K) * K;
    }

    std::cout << std::min(K - N, N) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
