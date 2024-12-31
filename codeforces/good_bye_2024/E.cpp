#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs_1(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& cnt_leaf, std::vector<int>& cnt_p) {
    if(G[v].size() == 1) {
        cnt_leaf[v] = 1;
    }

    bool has_leaf = G[v].size() == 1;
    for(int nei : G[v]) {
        if(G[nei].size() == 1) {
            has_leaf = true;
        }
        if(nei != p) {
            dfs_1(G, nei, v, cnt_leaf, cnt_p);
            cnt_leaf[v] += cnt_leaf[nei];
            cnt_p[v] += cnt_p[nei];
        }
    } 
    cnt_p[v] += has_leaf ? 0 : 1;
}

void dfs_2(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& cnt_leaf, std::vector<int>& cnt_p, int64_t& ans) {
    if(p == -1) {
        if(G[v].size() > 1) {
            ans += cnt_leaf[0];
        }
        int leaf = 0;
        for(int nei : G[v]) {
            if(G[nei].size() == 1) {
                leaf += 1;
            }
        }

        if(leaf) {
            for(int nei : G[v]) {
                if(G[nei].size() != 1) {
                    ans += int64_t(cnt_p[nei]) * (G[v].size() - leaf - 1);
                }
            }
        }
    } else {
        if(G[v].size() > 1) {
            ans += cnt_leaf[0];
        }

        int leaf = 0;
        for(int nei : G[v]) {
            if(G[nei].size() == 1) {
                leaf += 1;
            }
        }

        if(leaf) {
            ans += int64_t(cnt_p[0] - cnt_p[v]) * (G[v].size() - 1 - leaf);
            for(int nei : G[v]) {
                if(nei != p && G[nei].size() != 1) {
                    ans += int64_t(cnt_p[nei]) * (G[v].size() - leaf - 1);
                }
            }
        }
    }

    for(int nei : G[v]) {
        if(nei != p) {
            dfs_2(G, nei, v, cnt_leaf, cnt_p, ans);
        } 
    }
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    int64_t ans = 0;
    std::vector<int> cnt_leaf(N, 0);
    std::vector<int> cnt_p(N, 0);

    dfs_1(G, 0, -1, cnt_leaf, cnt_p);
    dfs_2(G, 0, -1, cnt_leaf, cnt_p, ans);

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
