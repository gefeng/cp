#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <numeric>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);

    if(M == N) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<int64_t> gaps;
    for(int i = 1; i < N; i++) {
        gaps.push_back(A[i] - A[i - 1]);
    }

    std::ranges::sort(gaps);
    
    int64_t ans = A.back() - A.front();
    
    for(int i = 0; i < M - 1; i++) {
        ans -= gaps[N - 1 - 1 - i];
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
