#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <ranges>

void run_case() {
    int64_t N;
    int M;
    std::cin >> N >> M;

    std::vector<std::pair<int64_t, int64_t>> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    auto cmp = [](const auto& a, const auto& b) {
        return a.first - a.second > b.first - b.second;
    };
    std::priority_queue<std::pair<int64_t, int64_t>, std::vector<std::pair<int64_t, int64_t>>, decltype(cmp)> pq(cmp);

    for(int i = 0; i < M; i++) {
        if(A[i].first <= N) {
            pq.emplace(A[i].first, A[i].second);
        }
    }

    int64_t ans = 0;
    while(!pq.empty()) {
        while(!pq.empty() && pq.top().first > N) {
            pq.pop();
        }
        if(pq.empty()) {
            break;
        }

        auto [a, b] = pq.top(); 
        int64_t d = a - b;
        int64_t x = (N - b) / d;
        ans += x;
        N = N - x * d;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
