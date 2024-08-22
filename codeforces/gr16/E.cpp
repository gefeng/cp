#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

bool dfs(std::vector<std::set<int>>& G, int v, int p, int& cnt_bud, int& cnt_leaf) {
    std::vector<int> remove;
    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }
        if(dfs(G, nei, v, cnt_bud, cnt_leaf)) {
            remove.push_back(nei);  
        }
    }

    for(int x : remove) {
        G[v].erase(x);
    }

    bool is_bud = p != -1;
    
    if(G[v].size() == 1) {
        is_bud = false;
    }

    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }
         
        if(G[nei].size() > 1) {
            is_bud = false;
        }
    }
    
    if(is_bud) {
        cnt_bud += 1;
        cnt_leaf += G[v].size() - 1;
    }
    
    return is_bud;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::set<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].insert(V);
        G[V].insert(U);
    }

    int cnt_bud = 0;
    int cnt_leaf = 0;
    dfs(G, 0, -1, cnt_bud, cnt_leaf);

    int ans = cnt_leaf + G[0].size() - cnt_bud;
    if(G[0].empty()) {
        ans += 1;
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
