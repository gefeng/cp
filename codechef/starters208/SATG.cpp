#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N, X, K;
    std::cin >> N >> X >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);

    for(int i = N - 1; i >= 0 && K; i--, K--) {
        A[i] = 0;
        X += 100;
    }

    std::ranges::sort(A);

    std::cout << (A.end() - std::upper_bound(A.begin(), A.end(), X)) + 1 << '\n';
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
