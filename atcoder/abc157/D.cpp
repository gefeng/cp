#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

struct dsu {
    int n;
    std::vector<int> p;
    std::vector<int> w;

    dsu(int n) : n(n) {
        p.resize(n, -1);
        w.resize(n, 1);
    }

    int find(int i) {
        if(p[i] < 0) {
            return i;
        }
        return p[i] = find(p[i]);
    }

    void unite(int i, int j) {
        int x = find(i);
        int y = find(j);
        if(x == y) {
            return;
        }

        if(w[x] >= w[y]) {
            p[y] = x;
            w[x] += w[y];
        } else {
            p[x] = y;
            w[y] += w[x];
        }
    }

    bool same(int i, int j) {
        return find(i) == find(j); 
    }

    int size(int i) {
        return w[find(i)];
    }
};

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<std::pair<int, int>> A(M);
    std::vector<std::pair<int, int>> B(K);
    std::vector<int> ans(N, 0);
    dsu uf(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;

        A[i] = {U, V};

        uf.unite(U, V);
    }

    for(int i = 0; i < K; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;

        B[i] = {U, V};
    }

    for(int i = 0; i < N; i++) {
        ans[i] = uf.size(i) - 1;
    } 

    for(auto [u, v] : B) {
        if(uf.same(u, v)) {
            ans[u] = std::max(0, ans[u] - 1);
            ans[v] = std::max(0, ans[v] - 1);
        }
    }

    for(auto [u, v] : A) {
        ans[u] = std::max(0, ans[u] - 1);
        ans[v] = std::max(0, ans[v] - 1);
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
