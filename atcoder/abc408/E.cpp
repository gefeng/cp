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

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<std::tuple<int, int, int>>> G(N);
    std::vector<std::pair<int, int>> E(M);
    for(int i = 0; i < M; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, W, i);
        G[V].emplace_back(U, W, i);
        E[i] = {U, V};
    }

    int ans = 0;
    std::vector<int> removed(M, 0);
    for(int i = 29; i >= 0; i--) {
        std::queue<int> q;
        std::vector<int> best(N, -1);
        q.push(0); 
        best[0] = 0;
        
        std::vector<int> tmp;
        while(!q.empty()) {
            int v = q.front();
            q.pop();

            for(auto [nei, w, e] : G[v]) {
                if(removed[e]) {
                    continue;
                }
                int b = w & (1 << i) ? 1 : 0;
                if(b) {
                    tmp.push_back(e);
                }
                if(best[nei] == -1 && b == 0) {
                    best[nei] = b;
                    q.push(nei);
                }
            }
        }

        if(best[N - 1] != 0) {
            ans |= 1 << i; 
        } else if(best[N - 1] == 0) {
            for(int e : tmp) {
                removed[e] = 1;
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
