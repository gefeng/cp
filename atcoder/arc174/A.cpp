#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)1e18;

void run_case() {
    int N, C;
    std::cin >> N >> C;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t sum = 0;
    int64_t max_sum = -INF;
    int64_t min_sum = INF;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        max_sum = std::max(max_sum, sum);
        sum = std::max((int64_t)0, sum);
    }

    sum = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        min_sum = std::min(min_sum, sum);
        sum = std::min((int64_t)0, sum);
    }

    sum = 0;;
    for(int x : A) {
        sum += x;
    }

    int64_t ans = sum;
    ans = std::max(ans, sum + max_sum * (C - 1));
    ans = std::max(ans, sum + min_sum * (C - 1));
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
