#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X, K;
    std::cin >> N >> X >> K;

    int r1 = X % K;
    int r2 = (N - X) % K;

    std::cout << std::max(r1, r2) - std::min(r1, r2) << '\n';
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
