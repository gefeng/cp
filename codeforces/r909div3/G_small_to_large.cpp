#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void dfs(std::vector<std::vector<int>>& G, std::vector<int>& pos, std::vector<std::vector<std::array<int, 3>>>& queries, 
        std::vector<std::set<int>>& save, int v, int p, std::vector<int>& ans) {
    int big = -1;
    int max_size = 0;
    for(int nei : G[v]) {
        if(nei != p) {
            dfs(G, pos, queries, save, nei, v, ans);
            if(save[nei].size() > max_size) {
                max_size = save[nei].size();
                big = nei;
            }
        }
    }

    if(big != -1) {
        std::swap(save[v], save[big]);
    }

    save[v].insert(pos[v]);
    for(int nei : G[v]) {
        if(nei != p && nei != big) {
            for(int x : save[nei]) {
                save[v].insert(x);
            }
        }
    }

    for(auto [l, r, i] : queries[v]) {
        auto it = save[v].lower_bound(l);
        if(it != save[v].end() && *it <= r) {
            ans[i] = 1;
        } 
    }
}

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int> A(N);
    std::vector<int> pos(N, -1);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        pos[A[i] - 1] = i;
    }

    std::vector<std::vector<std::array<int, 3>>> queries(N);
    for(int i = 0; i < Q; i++) {
        int L, R, X;
        std::cin >> L >> R >> X;
        L -= 1;
        R -= 1;
        X -= 1;

        queries[X].push_back({L, R, i});
    }

    std::vector<std::set<int>> save(N);
    std::vector<int> ans(Q, 0);
    dfs(G, pos, queries, save, 0, -1, ans);

    for(int i = 0; i < Q; i++) {
        std::cout << (ans[i] ? "Yes" : "No") << '\n';
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
