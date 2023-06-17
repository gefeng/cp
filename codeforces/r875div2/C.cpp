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
    int N;
    std::cin >> N;

    std::vector<std::vector<std::pair<int, int>>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, i); 
        G[V].emplace_back(U, i);
    }

    std::vector<int> d(N, -1);
    std::queue<std::pair<int, int>> q;
    q.emplace(0, -1); 
    d[0] = 1;

    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            std::pair<int, int> cur = q.front();
            q.pop();

            int v = cur.first;
            int e = cur.second;
            
            for(auto& nei : G[v]) {
                int nv = nei.first;
                int ne = nei.second;

                if(d[nv] != -1) {
                    continue;
                }
                
                if(ne > e) {
                    d[nv] = d[v];
                } else {
                    d[nv] = d[v] + 1;
                }

                q.emplace(nv, ne);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) { 
        ans = std::max(ans, d[i]);
    }
    
    std::cout << ans << '\n';
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
