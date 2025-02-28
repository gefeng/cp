#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

bool find_path(std::vector<std::vector<int>>& G, int T, int v, int p, std::vector<int>& path, std::vector<int>& in_path) {
    in_path[v] = 1;
    path.push_back(v);
    if(v == T) {
        return true;
    }

    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }
        
        if(find_path(G, T, nei, v, path, in_path)) {
            return true;
        }
    }

    in_path[v] = 0;
    path.pop_back();

    return false;
}

void dfs(std::vector<std::vector<int>>& G, std::vector<int>& in_path, int v, int p, int d, std::vector<std::pair<int, int>>& tmp) {
    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }
        dfs(G, in_path, nei, v, d + 1, tmp);
    }

    if(!in_path[v]) {
        tmp.emplace_back(v, d);
    }

}

void run_case() {
    int N, S, T;
    std::cin >> N >> S >> T;
    S -= 1;
    T -= 1;
    
    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int> path;
    std::vector<int> in_path(N, 0);
    find_path(G, T, S, -1, path, in_path);

    std::vector<int> ans;
    std::vector<std::pair<int, int>> all;
    for(int v : G[S]) {
        dfs(G, in_path, v, S, 0, all);
    }

    std::sort(all.begin(), all.end(), [](const auto& x, const auto& y) {
                return x.second > y.second;
            });
    for(auto [v, d] : all) {
        ans.push_back(v);
    }
    
    for(int v : path) {
        ans.push_back(v);
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] + 1 << " \n"[i == N - 1];
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
