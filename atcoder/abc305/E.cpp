#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <set>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<std::vector<int>> G(N);    
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int> best(N, -1);
    std::priority_queue<std::pair<int, int>> pq;

    for(int i = 0; i < K; i++) {
        int V, H;
        std::cin >> V >> H;
        V -= 1;

        pq.emplace(H, V);
        best[V] = H;
    }

    
    while(!pq.empty()) {
        std::pair<int, int> cur = pq.top();
        pq.pop();
        
        int d = cur.first;
        int v = cur.second;
        
        if(d == 0 || best[v] != d) {
            continue;
        }

        for(int nei : G[v]) {
            if(best[nei] < d - 1) {
                best[nei] = d - 1;
                pq.emplace(d - 1, nei);
            }
        }
    }

    std::vector<int> ans;
    for(int i = 0; i < N; i++) {
        if(best[i] != -1) {
            ans.push_back(i + 1);
        }
    }

    int sz = ans.size();
    std::cout << sz << '\n';
    for(int i = 0; i < sz; i++) {
        std::cout << ans[i] << " \n"[i == sz - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
