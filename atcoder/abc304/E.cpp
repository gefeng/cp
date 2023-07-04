#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

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
};

void run_case() {
    int N, M;
    std::cin >> N >> M;

    dsu uf(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        uf.unite(U, V);
    }

    std::map<int, std::set<int>> m;
    int K;
    std::cin >> K;
    for(int i = 0; i < K; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;

        int p1 = uf.find(U);
        int p2 = uf.find(V);

        m[p1].insert(p2);
        m[p2].insert(p1);
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;

        int p1 = uf.find(U);
        int p2 = uf.find(V);
        
        if(m.find(p1) != m.end() && m[p1].find(p2) != m[p1].end()) {
            std::cout << "No" << '\n';
        } else {
            std::cout << "Yes" << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
