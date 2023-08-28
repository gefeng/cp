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
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<int>> G(N);
    std::vector<int> indegree(N, 0);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        indegree[V] += 1;
    }

    std::queue<int> q;
    int winner = 0;
    for(int i = 0; i < N; i++) {
        if(indegree[i] == 0) {
            q.push(i);
            winner = i;
        }
    }
    
    if(q.size() != 1) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int> vis(N, 0);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        vis[v] = 1;
        for(int nei : G[v]) {
            if(--indegree[nei] == 0) {
                q.push(nei);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(!vis[i]) {
            std::cout << -1 << '\n';
            return;
        }
    }

    std::cout << winner + 1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
