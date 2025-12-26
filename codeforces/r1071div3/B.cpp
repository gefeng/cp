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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t sum = 0;
    for(int i = 0; i < N - 1; i++) {
        sum += std::abs(A[i] - A[i + 1]);
    }

    int64_t ans = sum;
    for(int i = 0; i < N; i++) {
        int64_t l = i == 0 ? 0 : std::abs(A[i - 1] - A[i]);
        int64_t r = i == N - 1 ? 0 : std::abs(A[i] - A[i + 1]);
        int64_t x = i == 0 || i == N - 1 ? 0 : std::abs(A[i - 1] - A[i + 1]);
        ans = std::min(ans, sum - l - r + x);
    }

    std::cout << ans << '\n';
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
