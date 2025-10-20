#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void bipartite(std::vector<std::set<int>>& G, int v, int c, std::vector<int>& color) {
    color[v] = c;
    for(int nei : G[v]) {
        if(color[nei] == -1) {
            bipartite(G, nei, c ^ 1, color);
        }
    }
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
    
    std::vector<std::pair<int, int>> ans;
    
    std::vector<int> color(N, -1);
    bipartite(G, 0, 0, color);

    std::vector<int> leaf;
    for(int i = 0; i < N; i++) {
        if(G[i].size() == 1 && i != N - 1) {
            leaf.push_back(i);
        }
    }

    int c = color[0];
    while(!leaf.empty()) {
        int v = leaf.back();
        leaf.pop_back();
        if(c == color[v]) {
            ans.emplace_back(1, 0);
            c ^= 1;
        } else {
            ans.emplace_back(1, 0);
            ans.emplace_back(1, 0);
        }
        int u = *G[v].begin();
        G[u].erase(v);
        G[v].clear();
        ans.emplace_back(2, v);
        if(G[u].size() == 1 && u != N - 1) {
            leaf.push_back(u);
        } 
    }


    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i].first;
        if(ans[i].first == 2) {
            std::cout << ' ' << ans[i].second + 1 << '\n';
        } else {
            std::cout << '\n';
        }
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
