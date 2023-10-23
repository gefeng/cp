#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int64_t INF = (int64_t)1e18;

void run_case() {
    int N; 
    int64_t A, B, C;
    std::cin >> N >> A >> B >> C;

    std::vector<std::vector<int64_t>> D(N, std::vector<int64_t>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> D[i][j];
        }
    }

    std::vector<std::vector<int64_t>> dp(N, std::vector<int64_t>(2, INF));

    auto cmp = [](const auto& a, const auto& b) {
        return a[0] > b[0];
    };

    std::priority_queue<std::array<int64_t, 3>, std::vector<std::array<int64_t, 3>>, decltype(cmp)> pq(cmp);
    pq.push({0, 0, 0});
    pq.push({0, 0, 1});
    dp[0][0] = 0;
    dp[0][1] = 0;
    while(!pq.empty()) {
        std::array<int64_t, 3> cur = pq.top();
        pq.pop();
        int64_t t = cur[0];
        int v = cur[1];
        int w = cur[2];

        if(t != dp[v][w]) {
            continue;
        }
        
        for(int i = 0; i < N; i++) {
            if(i != v) {
                if(w == 1) {
                    int64_t nt = t + D[v][i] * B + C;
                    if(dp[i][1] > nt) {
                        dp[i][1] = nt; 
                        pq.push({nt, i, 1});
                    }
                } else {
                    int64_t nt = t + D[v][i] * A;
                    if(dp[i][0] > nt) {
                        dp[i][0] = nt;
                        pq.push({nt, i, 0});
                    }
                    
                    nt = t + D[v][i] * B + C;
                    if(dp[i][1] > nt) {
                        dp[i][1] = nt;
                        pq.push({nt, i, 1});
                    }
                } 
            }
        }
    }
    
    std::cout << std::min(dp[N - 1][0], dp[N - 1][1]) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
