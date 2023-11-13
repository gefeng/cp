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
    std::vector<int64_t> w;
    
    dsu(int n) : n(n) {
        p.resize(n, -1);
        w.resize(n, 0);
    }

    int find(int i) {
        if(p[i] < 0) {
            return i;
        }
        
        int np = find(p[i]);
        w[i] = w[p[i]] + w[i];
        
        return p[i] = np;
    }

    bool unite(int i, int j, int v) {
        int x = find(i);
        int y = find(j);
        if(x == y) {
            return w[j] - w[i] == v;
        }

        p[x] = y;
        w[x] = w[j] - w[i] - v;

        return true;
    }
};

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    dsu uf(N);
    
    for(int i = 0; i < Q; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;
        U -= 1;
        V -= 1;

        if(uf.unite(U, V, W)) {
            std::cout << i + 1 << ' ';
        }
    }

    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
