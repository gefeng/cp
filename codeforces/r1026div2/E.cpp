#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int MAX = int(1e9);

void dfs(std::map<int, std::vector<std::pair<int, int>>>& G, int v, std::vector<int>& vis, std::vector<int>& path) {
    while(!G[v].empty()) {
        auto [nei, e] = G[v].back();
        G[v].pop_back();
        if(!vis[e]) {
            vis[e] = 1;
            dfs(G, nei, vis, path);
            path.push_back(e);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::map<int, std::vector<std::pair<int, int>>> G;
    std::map<int, int> degree;
    for(int i = 0; i < N; i++) {
        int U, V;
        std::cin >> U >> V;
        G[U].emplace_back(V + MAX, i);
        G[V + MAX].emplace_back(U, i);
        degree[U] += 1;
        degree[V + MAX] += 1;
    }

    int cnt_odd = 0;
    int st = -1;
    for(auto [v, d] : degree) {
        if(d % 2 == 1) {
            cnt_odd += 1;
            st = v;
        }
    }

    if(cnt_odd != 0 && cnt_odd != 2) {
        std::cout << "No" << '\n';
        return;
    }

    st = st == -1 ? degree.begin()->first : st; 
    
    std::vector<int> vis(N, 0);
    std::vector<int> path;
    dfs(G, st, vis, path);

    if(path.size() != N) {
        std::cout << "No" << '\n';
        return;
    }

    std::cout << "Yes" << '\n';
    for(int i = N - 1; i >= 0; i--) {
        std::cout << path[i] + 1 << " \n"[i == 0];
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
