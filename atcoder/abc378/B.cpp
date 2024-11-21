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
    
    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int T, D;
        std::cin >> T >> D;

        T -= 1;

        auto [q, r] = A[T];
        int x = ((r - D % q) + q) % q;
        std::cout << D + x << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
