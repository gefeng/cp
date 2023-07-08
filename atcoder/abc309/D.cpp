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
    int N1, N2, M;
    std::cin >> N1 >> N2 >> M;

    std::vector<std::vector<int>> G(N1 + N2);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    auto bfs = [&](int st) {
        std::queue<int> q;
        std::vector<int> vis(N1 + N2, 0);
        
        q.emplace(st);
        vis[st] = 1;
        
        int d = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int v = q.front();
                q.pop();

                for(int nei : G[v]) {
                    if(!vis[nei]) {
                        vis[nei] = 1;
                        q.emplace(nei);
                    }
                }
            }
            d += 1;
        }

        return d - 1;
    };

    std::cout << bfs(0) + bfs(N1 + N2 - 1) + 1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
