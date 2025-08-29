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
    std::vector<int> c;
    dsu(int _n) : n(_n), p(n, -1), w(n, 1), c(n, 0) {}

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
            c[x] += c[y];
            w[x] += w[y];
        } else {
            p[x] = y;
            c[y] += c[x];
            w[y] += w[x];
        }
    }

    bool same(int i, int j) {
        return find(i) == find(j);
    }
};

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    dsu uf(N);
    std::vector<int> color(N, 0);

    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        if(T == 1) {
            int U, V;
            std::cin >> U >> V;
            U -= 1;
            V -= 1;
            uf.unite(U, V);
        } else if(T == 2) {
            int V;
            std::cin >> V;
            V -= 1;
            if(color[V] == 1) {
                uf.c[uf.find(V)] -= 1;
            }
            color[V] ^= 1;
            if(color[V] == 1) {
                uf.c[uf.find(V)] += 1;
            }
        } else {
            int V;
            std::cin >> V;
            V -= 1;
            std::cout << (uf.c[uf.find(V)] ? "Yes" : "No") << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
