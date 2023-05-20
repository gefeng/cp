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

    std::vector<std::vector<int>> G(N + M);
    for(int i = 0; i < N; i++) {
        int A;
        std::cin >> A;

        for(int j = 0; j < A; j++) {
            int S;
            std::cin >> S;

            S -= 1;
            G[i + M].push_back(S);     
            G[S].push_back(i + M);
        }
    }

    std::queue<int> q;
    std::vector<bool> vis(N + M, false);

    q.emplace(0); 
    vis[0] = true;
    
    int d = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int v = q.front();
            q.pop();

            if(v == M - 1) {
                std::cout << (d - 1) / 2 << '\n';
                return;
            }

            for(int nei : G[v]) {
                if(!vis[nei]) {
                    vis[nei] = true;
                    q.emplace(nei);
                }
            }
        }

        d += 1;
    }

    std::cout << -1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
