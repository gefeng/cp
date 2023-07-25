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
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> B(K);
    std::vector<int64_t> cost(N, INF);
    for(int i = 0; i < K; i++) {
        std::cin >> B[i];
        B[i] -= 1;
        cost[B[i]] = 0;
    }

    std::vector<std::vector<int>> G(N);
    std::vector<int> indegree(N, 0);
    for(int i = 0; i < N; i++) {
        int M;
        std::cin >> M;

        if(M > 0) {
            for(int j = 0; j < M; j++) {
                int V;
                std::cin >> V;
                V -= 1;
                
                G[V].push_back(i);
                indegree[i] += 1;
            }
        }

        cost[i] = std::min(cost[i], (int64_t)A[i]);
    }

    std::queue<int> q;
    std::vector<int64_t> mix(N, 0);
    for(int i = 0; i < N; i++) {
        if(indegree[i] == 0) {
            q.emplace(i);
        }
    }

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        
        for(int nei : G[v]) {
            mix[nei] += cost[v];
            if(--indegree[nei] == 0) {
                q.emplace(nei);
                cost[nei] = std::min(cost[nei], mix[nei]);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << cost[i] << " \n"[i == N - 1];
    }
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
