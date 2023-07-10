#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

struct dsu {
    int _n;
    std::vector<int> _p;
    std::vector<int> _w;

    dsu(int n) : _n(n) {
        _p.resize(_n, -1);
        _w.resize(_n, 1);
    }

    int find(int i) {
        if(_p[i] < 0) {
            return i;
        }
        return _p[i] = find(_p[i]);
    }
    
    void unite(int i, int j) {
        int x = find(i);
        int y = find(j);
        if(x == y) {
            return;
        }

        if(_w[x] >= _w[y]) {
            _p[y] = x;
            _w[x] += _w[y];
        } else {
            _p[x] = y;
            _w[y] += _w[x];
        }
    }

    bool same(int i, int j) {
        return find(i) == find(j);
    }

    int size(int i) {
        return _w[find(i)];
    }
};

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> E;
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        E.emplace_back(U, V);
    }

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    dsu uf(N);
    for(auto [u, v] : E) {
        if(!uf.same(u, v)) {
            if(A[u] != A[v]) {
                uf.unite(u, v);
            }
        }
    }

    for(auto [u, v] : E) {
        if(uf.same(u, v) && A[u] == A[v]) {
            std::cout << "Yes" << '\n';
            return;
        }
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
