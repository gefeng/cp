#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int MAX = 10;

struct DSU {
    int n;
    std::vector<int> p;
    std::vector<int> w;
    std::vector<std::set<int>> kth;
    DSU(int _n) : n(_n), p(n, -1), w(n, 1), kth(n) {
        for(int i = 0; i < n; i++) {
            kth[i].insert(i);
        }
    }
    
    int find(int i) {
        if(p[i] < 0) {
            return i;
        }
        return p[i] = find(p[i]);
    }

    int get_kth(int i, int k) {
        int x = find(i); 
        if(kth[x].size() < k) {
            return -1;
        }
        int cnt = 0;
        int res = 0;
        for(auto it = std::prev(kth[x].end()); cnt < k; cnt++) {
            res = *it;
            if(it != kth[x].begin()) {
                it = std::prev(it);
            }
        }
        return res;
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
            
            kth[x].insert(kth[y].begin(), kth[y].end());
            kth[y].clear();
            while(kth[x].size() > MAX) {
                kth[x].erase(kth[x].begin());
            }
        } else {
            p[x] = y;
            w[y] += w[x];

            kth[y].insert(kth[x].begin(), kth[x].end());
            kth[x].clear();
            while(kth[y].size() > MAX) {
                kth[y].erase(kth[y].begin());
            }
        }
    }

    bool same(int i, int j) {
        return find(i) == find(j);
    }
};

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    DSU uf(N); 
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        if(T == 1) {
            int U, V;
            std::cin >> U >> V;
            U -= 1;
            V -= 1;
            uf.unite(U, V);
        } else {
            int V, K;
            std::cin >> V >> K;
            V -= 1;
            
            int res = uf.get_kth(V, K);
            std::cout << (res == -1 ? res : res + 1) << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
