#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int MAX = static_cast<int>(1e6);

void run_case() {
    int N, D;
    std::cin >> N >> D;

    std::vector<std::pair<int, int>> A;
    for(int i = 0; i < N; i++) {
        int X, Y;
        std::cin >> X >> Y;
        if(Y - X < D) {
            continue;
        }
        A.emplace_back(X, Y);
    }

    N = A.size();
    int64_t ans = 0;
    std::vector<int64_t> diff(MAX + 10, 0);
    
    for(auto [l, r] : A) {
        diff[l]++;
        diff[r - D + 1]--;
    }

    int64_t rolling = 0;
    for(int i = 1; i <= MAX; i++) {
        rolling += diff[i];
        ans += rolling * (rolling - 1) / 2;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
