#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> diff(N + 10, 0);
    for(int i = 0; i < M; i++) {
        int L, R;
        std::cin >> L >> R;

        diff[L] += 1;
        diff[R + 1] -= 1;
    }

    int sum = 0;
    int ans = INF;
    for(int i = 1; i <= N; i++) {
        sum += diff[i];
        ans = std::min(ans, sum);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
