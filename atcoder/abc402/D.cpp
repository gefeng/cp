#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> A(M);
    std::map<int, int> m;
    for(int i = 0; i < M; i++) {
        std::cin >> A[i].first >> A[i].second;
        m[(A[i].first + A[i].second) % N] += 1;
    }

    int64_t ans = int64_t(M - 1) * M / 2;
    
    for(auto [sum, cnt] : m) {
        ans -= int64_t(cnt - 1) * cnt / 2;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
