#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> suffix_max(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        suffix_max[i] = std::max(suffix_max[i - 1], A[N - i] + N - i);
    }

    int ans = INF;
    int prefix_max = 0;
    for(int i = 0; i < N; i++) {
        int x = std::max(A[i], std::max(prefix_max, suffix_max[N - i - 1]));
        ans = std::min(ans, x);
        prefix_max = std::max(prefix_max, A[i] + (N - 1 - i));
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
