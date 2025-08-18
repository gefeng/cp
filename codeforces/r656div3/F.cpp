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

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::set<int>> G(N);
    std::vector<int> degree(N, 0);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].insert(V);
        G[V].insert(U);
        degree[U] += 1;
        degree[V] += 1;
    }

    if(K == 1) {
        std::cout << N - 1 << '\n';
        return;
    }

    std::vector<std::vector<int>> leaves(N);
    std::map<int, std::set<int>> m;
    for(int v = 0; v < N; v++) {
        for(int nei : G[v]) {
            if(degree[nei] == 1) {
                leaves[v].push_back(nei);
            }
        }

        m[leaves[v].size()].insert(v);
    }

    int ans = 0;
    while(!m.empty()) {
        auto& [f, s] = *m.rbegin();
        if(f < K) {
            break;
        }
        
        int v = *s.begin();
        int c = 0;
        std::vector<int> remove;
        while(c != K) {
            remove.push_back(leaves[v].back());
            leaves[v].pop_back();
            c += 1;
        }

        ans += 1;
        
        degree[v] -= K;
        m[f - K].insert(v);
        s.erase(v);
        if(s.empty()) {
            m.erase(f);
        }

        for(int u : remove) {
            m[0].erase(u);
            G[v].erase(u);
        }
        if(m[0].empty()) {
            m.erase(0);
        }

        if(degree[v] == 1) {
            int u = *G[v].begin();
            int size = leaves[u].size();
            m[size].erase(u);
            if(m[size].empty()) {
                m.erase(size);
            }
            leaves[u].push_back(v);
            m[size + 1].insert(u); 
        }
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
