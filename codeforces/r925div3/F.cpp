#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <queue>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::set<int>> G(N);
    for(int i = 0; i < K; i++) {
        int pre = -1;
        for(int j = 0; j < N; j++) {
            int V;
            std::cin >> V;
            V -= 1;

            if(j == 0) {
                continue;
            }

            if(pre != -1) {
                G[pre].insert(V);
            }
            pre = V;
        }
    } 

    std::vector<int> indegree(N, 0);
    for(int v = 0; v < N; v++) {
        for(int u : G[v]) {
            indegree[u] += 1;
        }
    }

    std::queue<int> q;
    for(int v = 0; v < N; v++) {
        if(indegree[v] == 0) {
            q.emplace(v);
        }
    }

    int cnt = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();

        cnt += 1;
        
        for(int nei : G[v]) {
            if(--indegree[nei] == 0) {
                q.emplace(nei);
            }
        }
    }

    std::cout << (cnt == N ? "Yes" : "No") << '\n';
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
