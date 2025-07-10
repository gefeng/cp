#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr std::array<int, 8> DR = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr std::array<int, 8> DC = {1, 0, -1, 0, 1, -1, 1, -1};

struct dsu {
    int n_;
    std::vector<int> p_;
    std::vector<int> w_;
    
    dsu(int n) : n_(n), p_(n, -1), w_(n, 1) {}

    int find(int i) {
        if(p_[i] < 0) {
            return i;
        }
        return p_[i] = find(p_[i]);
    }
    
    void unite(int i, int j) {
        int x = find(i);
        int y = find(j);
        if(x == y) {
            return;
        }
        if(w_[x] >= w_[y]) {
            p_[y] = x;
            w_[x] += w_[y];
        } else {
            p_[x] = y;
            w_[y] += w_[x];
        }
    }

    bool same(int i, int j) {
        return find(i) == find(j);
    }
};

void run_case() {
    int H, W, K;
    std::cin >> H >> W >> K;
    
    dsu uf(K + 4);

    std::vector<std::pair<int, int>> A(K);
    std::map<std::pair<int, int>, int> m;
    for(int i = 0; i < K; i++) {
        std::cin >> A[i].first >> A[i].second;
        m[{A[i].first, A[i].second}] = i;
    }

    for(int i = 0; i < K; i++) {
        auto [x, y] = A[i];
        for(int d = 0; d < 8; d++) {
            int r = x + DR[d];
            int c = y + DC[d];
            if(r > 0 && c > 0 && r <= H && c <= W && m.find({r, c}) != m.end()) {
                uf.unite(m[{r, c}], i);
            }
        }
        if(x == 1) {
            uf.unite(i, K);
        } 
        if(x == H) {
            uf.unite(i, K + 2);
        }
        if(y == 1) {
            uf.unite(i, K + 3);
        }
        if(y == W) {
            uf.unite(i, K + 1);
        }
    }

    std::cout << (uf.same(K, K + 2) || uf.same(K + 1, K + 3) || uf.same(K, K + 3) || uf.same(K + 1, K + 2) ? "No" : "Yes") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
