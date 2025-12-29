#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> suffix(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        suffix[i] = suffix[i - 1] - A[N - i];
    }

    int64_t prefix = 0;
    int64_t ans = -INF;
    for(int i = 0; i < N; i++) {
        ans = std::max(ans, prefix + suffix[N - 1 - i]);

        prefix = i == 0 ? A[0] : (A[i] < 0 ? prefix - A[i] : prefix + A[i]);
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
