#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N, M, X;
    std::cin >> N >> M >> X;
    
    std::vector<std::vector<int>> G(N);
    std::vector<std::vector<int>> RG(N);
    
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        RG[V].push_back(U);
    }

    std::priority_queue<std::tuple<int64_t, int, int>, std::vector<std::tuple<int64_t, int, int>>, std::greater<std::tuple<int64_t, int, int>>> pq;
    std::vector<std::vector<int64_t>> cost(2, std::vector<int64_t>(N, INF));

    cost[0][0] = 0;
    pq.emplace(int64_t(0), 0, 0);
    
    while(!pq.empty()) {
        auto [c, v, f] = pq.top();
        pq.pop();
        
        if(c != cost[f][v]) {
            continue;
        } 

        if(cost[f ^ 1][v] > c + X) {
            cost[f ^ 1][v] = c + X;
            pq.emplace(c + X, v, f ^ 1);
        }

        if(f) {
            for(int nei : RG[v]) {
                if(cost[f][nei] > c + 1) {
                    cost[f][nei] = c + 1;
                    pq.emplace(c + 1, nei, f);
                }
            }
        } else {
            for(int nei : G[v]) {
                if(cost[f][nei] > c + 1) {
                    cost[f][nei] = c + 1;
                    pq.emplace(c + 1, nei, f);
                }
            }
        }
    }

    std::cout << std::min(cost[0][N - 1], cost[1][N - 1]) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
