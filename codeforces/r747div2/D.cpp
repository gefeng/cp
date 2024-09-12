#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

bool dfs(std::vector<std::vector<std::pair<int, int>>>& G, std::vector<std::vector<std::pair<int, int>>>& RG, 
        int v, int c, std::map<int, int>& m) {
    m[v] = c;
    
    for(auto [nei, x] : G[v]) {
        if(m.find(nei) != m.end()) {
            if(c == 0 && m[nei] != (x ^ 1)) {
                return false; 
            }
            if(c == 1 && m[nei] != x) {
                return false;
            }
        } else {
            if(!dfs(G, RG, nei, c == 0 ? (x ^ 1) : x, m)) {
                return false;
            }
        } 
    }

    for(auto [nei, x] : RG[v]) {
        if(m.find(nei) != m.end()) {
            if(m[nei] == 0 && x == c) {
                return false; 
            }
            if(m[nei] == 1 && x != c) {
                return false;
            }
        } else {
            if(!dfs(G, RG, nei, x == c ? 1 : 0, m)) {
                return false;
            }
        }
    }

    return true;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<std::pair<int, int>>> G(N);
    std::vector<std::vector<std::pair<int, int>>> RG(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::string S;
        std::cin >> U >> V >> S;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, S == "imposter" ? 0 : 1);
        RG[V].emplace_back(U, S == "imposter" ? 0 : 1);
    }

    std::vector<int> vis(N, 0); 

    auto solve = [&](int st) {
        int res = -1;
        for(int i = 0; i < 2; i++) {
            std::map<int, int> m;
            bool ok = dfs(G, RG, st, i, m);
            if(!ok) {
                continue; 
            }

            int cnt = 0;
            for(auto [v, c] : m) {
                if(c == 0) {
                    cnt += 1;
                }
                vis[v] = 1;
            } 
            res = std::max(res, cnt);
        }
        return res;
    };

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(vis[i]) {
            continue;
        }

        int res = solve(i);
        if(res == -1) {
            std::cout << -1 << '\n';
            return;
        }
        ans += res;
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
