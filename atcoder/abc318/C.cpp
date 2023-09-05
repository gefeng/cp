#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, D, P;
    std::cin >> N >> D >> P;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end(), std::greater<int>());
    int64_t ans = 0;
    for(int i = 0; i < N; i += D) {
        int64_t sum = 0;
        for(int j = 0; j < D && i + j < N; j++) {
            sum += A[i + j];
        }

        ans += std::min(sum, (int64_t)P);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
