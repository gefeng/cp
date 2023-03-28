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
    
    dsu(int _n) : n(_n) {
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
    int N;
    std::cin >> N;

    std::vector<int> p(N, -1);
    for(int i = 0; i < N - 1; i++) {
        int P;
        std::cin >> P;
        P -= 1;

        p[i + 1] = P;
    }

    std::vector<int> save_min(N, -1);
    for(int i = 0; i < N; i++) {
        save_min[i] = i;
    }

    dsu uf(N);

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;

        if(T == 1) {
            int U, V;
            std::cin >> U >> V;
            U -= 1;
            V -= 1;

            int x = p[U];
            while(!uf.same(U, V)) {
                int min_v = std::min(save_min[uf.find(U)], save_min[uf.find(x)]);
                uf.unite(U, x); 
                save_min[uf.find(U)] = min_v;
                x = p[min_v];
            }
        } else {
            int X;
            std::cin >> X;
            X -= 1;

            std::cout << save_min[uf.find(X)] + 1 << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
