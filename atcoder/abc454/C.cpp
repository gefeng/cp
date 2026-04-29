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
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U--;
        V--;
        G[U].push_back(V);
    }

    std::queue<int> q;
    std::vector<int> vis(N, 0);
    q.push(0);
    vis[0] = 1;

    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int v = q.front();
            q.pop();
            
            for(int u : G[v]) {
                if(!vis[u]) {
                    vis[u] = 1;
                    q.push(u);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(vis[i]) {
            ans++;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
