#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

struct fenwick_tree {
    int n;
    std::vector<int> ft;
    
    fenwick_tree(int size) : n(size + 1) {
        ft.resize(n, 0);
    }

    void update(int i, int v) {
        for(++i; i < n; i += i & -i) {
            ft[i] += v;
        }
    }

    int query(int i) {
        int res = 0;
        for(++i; i > 0; i -= i & -i) {
            res += ft[i];
        }
        return res;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

struct q {
    int l, r, x, id, cnt;
    q(int l, int r, int x, int id) : l(l), r(r), x(x), id(id), cnt(0) {};
};

void dfs(std::vector<std::vector<int>>& G, std::vector<int>& pos, std::vector<std::vector<q>>& queries, 
        fenwick_tree& ft, int v, int p, std::vector<int>& ans) {
    for(auto& x : queries[v]) {
        int cnt = ft.query(x.l, x.r);
        x.cnt = cnt;
    }
    
    ft.update(pos[v], 1);

    for(int nei : G[v]) {
        if(nei != p) {
            dfs(G, pos, queries, ft, nei, v, ans);
        }
    }

    for(auto& x : queries[v]) {
        int cnt = ft.query(x.l, x.r);
        if(x.cnt < cnt) {
            ans[x.id] = 1;
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

    std::vector<std::vector<q>> queries(N);
    for(int i = 0; i < Q; i++) {
        int L, R, X;
        std::cin >> L >> R >> X;
        L -= 1;
        R -= 1;
        X -= 1;

        queries[X].emplace_back(L, R, X, i);
    }

    fenwick_tree ft(N);
    std::vector<int> ans(Q, 0);
    dfs(G, pos, queries, ft, 0, -1, ans);

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
