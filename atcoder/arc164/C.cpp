#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    auto cmp = [](const auto& a, const auto& b) {
        return a.first - a.second < b.first - b.second;
    };
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);
    for(auto [a, b] : A) {
        pq.emplace(a, b);
    }

    int64_t ans = 0;
    while(!pq.empty()) {
        std::pair<int, int> cur = pq.top();
        pq.pop();

        pq.emplace(cur.second, cur.first);

        cur = pq.top();
        pq.pop();

        ans += cur.first;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
