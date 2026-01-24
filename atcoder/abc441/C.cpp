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
    int N, K;
    int64_t X;

    std::cin >> N >> K >> X;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A, std::greater<int>());
     
    int ans = N - K;
    for(int i = N - K; i < N; i++) {
        if(X > 0) {
            X -= A[i];
            ans += 1;
        }
    }

    std::cout << (X <= 0 ? ans : -1) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
