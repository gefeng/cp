#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

int dfs(std::vector<std::vector<int>>& rg, std::vector<int>& in_cycle, int v, int p) {
    int res = 1;
    for(int nei : rg[v]) {
        if(nei != p && !in_cycle[nei]) {
            res += dfs(rg, in_cycle, nei, v);
        }
    }
    return res;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<std::vector<int>> rg(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
        
        rg[A[i]].push_back(i);
    }

    int ans = 0;
    std::vector<int> in_cycle(N, 0);
    std::vector<int> vis(N, 0);
    for(int i = 0; i < N; i++) {
        if(vis[i]) {
            continue;
        }
        
        int v = i;
        std::set<int> s;
        while(true) {
            if(vis[v]) {
                break;
            }
            if(s.find(v) != s.end()) {
                break;
            }
            s.insert(v);
            v = A[v];
        }

        if(!vis[v]) {
            std::set<int> cycle;
            while(cycle.find(v) == cycle.end()) {
                cycle.insert(v);
                v = A[v];
            }

            for(int u : cycle) {
                in_cycle[u] = 1;
            }
        }

        for(int u : s) {
            vis[u] = 1;
        }
    }

    for(int i = 0; i < N; i++) {
        if(!in_cycle[i]) {
            continue;
        }
        for(int j : rg[i]) {
            if(!in_cycle[j]) {
                ans = std::max(ans, dfs(rg, in_cycle, j, i));
            }
        }
    }

    std::cout << ans + 2 << '\n';
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
