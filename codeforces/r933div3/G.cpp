#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>

void run_case() {
    int N, M, S, T;
    std::cin >> N >> M;
    
    std::vector<std::tuple<int, int, int>> E(M);
    std::map<int, int> colors;
    for(int i = 0; i < M; i++) {
        int U, V, C;
        std::cin >> U >> V >> C;
        U -= 1;
        V -= 1;
        E[i] = {U, V, C};
        colors[C] = 0;
    }

    std::cin >> S >> T;
    S -= 1;
    T -= 1;

    if(S == T) {
        std::cout << 0 << '\n';
        return;
    }

    int id = N;
    for(auto& [_, v] : colors) {
        v = id++;
    }

    std::vector<std::vector<int>> G(id);
    for(auto [u, v, c] : E) {
        G[u].push_back(colors[c]);
        G[v].push_back(colors[c]);
        G[colors[c]].push_back(u);
        G[colors[c]].push_back(v);
    }

    std::queue<int> q;
    std::vector<int> vis(id, 0);
    q.push(S);
    vis[S] = 1;

    int d = 1;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int v = q.front();
            q.pop();

            if(v == T) {
                std::cout << d / 2 << '\n';
                return;
            }

            for(int nei : G[v]) {
                if(!vis[nei]) {
                    vis[nei] = 1;
                    q.push(nei);
                } 
            }
        }
        d += 1;
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
