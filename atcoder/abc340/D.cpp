#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int64_t INF = (int64_t)2e18;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::array<int, 3>> A(N);
    for(int i = 0; i < N - 1; i++) {
        std::cin >> A[i][0] >> A[i][1] >> A[i][2];
        A[i][2] -= 1;
    }

    auto cmp = [](const auto& a, const auto& b) {
        return a.second > b.second;
    };

    std::priority_queue<std::pair<int, int64_t>, std::vector<std::pair<int, int64_t>>, decltype(cmp)> pq(cmp);
    std::vector<int64_t> best(N, INF);
    pq.emplace(0, 0);
    best[0] = 0;
    
    while(!pq.empty()) {
        auto [p, c] = pq.top();
        pq.pop();
        
        if(p == N - 1 || best[p] != c) {
            continue;
        }

        int np = p + 1;
        int64_t nc = c + A[p][0];
        
        if(best[np] > nc) {
            best[np] = nc;
            pq.emplace(np, nc);
        }

        np = A[p][2];
        nc = c + A[p][1];
        if(best[np] > nc) {
            best[np] = nc;
            pq.emplace(np, nc);
        }
    }

    std::cout << best[N - 1] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
