#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

bool dfs1(std::vector<std::vector<int>>& G, int B, int v, int p, std::vector<int>& path) {
    if(v == B) {
        path.push_back(v);
        return true;
    } 

    bool found = false;
    for(int nei : G[v]) {
        if(nei != p) {
            if(dfs1(G, B, nei, v, path)) {
                found = true;
            }
        }
    }

    if(found) {
        path.push_back(v); 
    }
    return found;
}

int dfs2(std::vector<std::vector<int>>& G, int v, int p) {
    int res = 0;
    for(int nei : G[v]) {
        if(nei != p) {
            res += dfs2(G, nei, v);   
        }
    }
    
    res += 2;

    return res;
}

int dfs3(std::vector<std::vector<int>>& G, int v, int p) {
    if(G[v].size() == 1 && p != -1) {
        return 0;
    }
    
    int res = 0;
    for(int nei : G[v]) {
        if(nei != p) {
            res = std::max(res, dfs3(G, nei, v));
        }
    }
    return res + 1;
}

void run_case() {
    int N, A, B;
    std::cin >> N >> A >> B;
    A -= 1;
    B -= 1;
    
    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    if(N == 1) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<int> path;
    dfs1(G, B, A, -1, path);
    std::reverse(path.begin(), path.end());
    
    int root = path.size() % 2 == 0 ? path[path.size() / 2 - 1] : path[path.size() / 2];
    int ans = path.size() / 2;
    ans += dfs2(G, root, -1) - 2;
    ans -= dfs3(G, root, -1);

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
