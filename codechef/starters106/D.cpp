#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int INF = (int)1e9;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<std::vector<int>> best(N, std::vector<int>(2, INF));
    best[0][0] = 0;
    std::queue<int> q;
    q.push(0); 

    int d = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int v = q.front();
            q.pop();

            int p = (d + 1) % 2;
            for(int nei : G[v]) {
                if(best[nei][p] == INF) {
                    best[nei][p] = d + 1;
                    q.push(nei);
                }
            }
        }
        d += 1;
    }

    int eve = 0;
    int odd = 0;
    for(int i = 0; i < N; i++) {
        eve = std::max(eve, best[i][0]);
        odd = std::max(odd, best[i][1]);
    }

    if(eve == INF && odd == INF) {
        std::cout << -1 << '\n';
        return;
    } 

    if(eve == INF) {
        std::cout << odd << '\n';
    } else if(odd == INF) {
        std::cout << eve << '\n';
    } else {
        std::cout << std::min(eve, odd) << '\n';
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
