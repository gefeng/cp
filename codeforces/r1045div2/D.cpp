#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int INF = static_cast<int>(2e9);

bool dfs(std::vector<std::vector<int>>& G, int b, int v, int p, std::vector<int>& diameter) {
    diameter.push_back(v);
    if(v == b) {
        return true;
    }
    
    for(int nei : G[v]) {
        if(nei != p) {
            if(dfs(G, b, nei, v, diameter)) {
                return true;
            }
        }
    }

    diameter.pop_back();
    return false;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int> dist(N, 0);
    std::vector<int> diameter;

    auto bfs = [&](int st) {
        std::queue<int> q;
        dist.assign(N, INF);

        q.push(st);
        dist[st] = 0;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int nei : G[v]) {
                if(dist[nei] > dist[v] + 1) {
                    dist[nei] = dist[v] + 1;
                    q.push(nei);
                }
            }
        }
    };

    bfs(0);
    int a = -1;
    int b = -1;
    int max_d = -1;
    for(int i = 0; i < N; i++) {
        if(max_d < dist[i]) {
            max_d = dist[i];
            a = i;
        }
    }

    bfs(a);
    max_d = -1;
    for(int i = 0; i < N; i++) {
        if(max_d < dist[i]) {
            max_d = dist[i];
            b = i;
        }
    }

    dfs(G, b, a, -1, diameter);
    
    max_d += 1;
    for(int i = 1; i < max_d - 1; i++) {
        int v = diameter[i];
        if(G[v].size() > 2) {
            for(int nei : G[v]) {
                if(nei != diameter[i - 1] && nei != diameter[i + 1]) {
                    std::cout << diameter[i + 1] + 1 << ' ' << v + 1 << ' ' << nei + 1 << '\n';
                    return;
                }
            }
        }
    }

    std::cout << -1 << '\n';
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
