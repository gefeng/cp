#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& vis) {
    vis.push_back(v);
    for(int nei : G[v]) {
        if(nei != p) {
            dfs(G, nei, v, vis);
        }
    }
}
    
void color(std::vector<std::vector<int>>& G, int v, int p, int& k, std::vector<int>& ans) {
    if(k) {
        ans[v] = 1;
        k -= 1;
    }

    for(int nei : G[v]) {
        if(nei != p) {
            color(G, nei, v, k, ans);
        }
    }
}


void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int> ans(N);
    if(K == N || K == 0) {
        std::cout << 1 << '\n';
        if(K == N) {
            ans.assign(N, 1);
        }
        for(int i = 0; i < N; i++) {
            std::cout << ans[i] << " \n"[i == N - 1];
        }
        return;
    }

    for(int v = 0; v < N; v++) {
        for(int u : G[v]) {
            std::vector<int> vis;
            dfs(G, u, v, vis);
            if(vis.size() == K) {
                std::cout << 2 << '\n';
                for(int x : vis) {
                    ans[x] = 1;
                } 
                for(int i = 0; i < N; i++) {
                    std::cout << ans[i] << " \n"[i == N - 1];
                }
                return;
            }
            
            if(N - vis.size() == K) {
                std::cout << 2 << '\n';
                for(int x : vis) {
                    ans[x] = -1;
                }
                for(int i = 0; i < N; i++) {
                    if(ans[i] != -1) {
                        ans[i] = 1;
                    } else {
                        ans[i] = 0;
                    }
                }
                for(int i = 0; i < N; i++) {
                    std::cout << ans[i] << " \n"[i == N - 1];
                }
                return;
            }
        }
    }

    std::cout << 3 << '\n';
    color(G, 0, -1, K, ans);
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
