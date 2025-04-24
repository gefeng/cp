#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

struct dsu {
    int n;
    std::vector<int> p;
    std::vector<int64_t> w;

    dsu(const std::vector<int64_t>& init_w) : n(init_w.size()), p(n, -1), w(init_w) {
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
    
    int64_t size(int i) {
        return w[find(i)];
    }
};

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<int64_t> init_w(N * 3, 0); 
    for(int i = 0; i < N; i++) {
        if(S[i] == '0') {
            init_w[i * 3] = i;
            init_w[i * 3 + 2] = N - 1 - i;
        } else {
            init_w[i * 3 + 1] = 1;
        }
    }

    dsu uf(init_w);

    for(int i = 1; i < N; i++) {
        if(S[i - 1] == '0') {
            if(S[i] == '0') {
                uf.unite((i - 1) * 3, i * 3);    
                uf.unite((i - 1) * 3 + 2, i * 3 + 2);
            } else {
                uf.unite((i - 1) * 3 + 2, i * 3 + 1);
            }
        } else {
            if(S[i] == '0') {
                uf.unite((i - 1) * 3 + 1, i * 3); 
            }
        }
    }

    int64_t ans = 0;
    for(int i = 0; i < N * 3; i++) {
        if(uf.find(i) == i) {
            ans = std::max(ans, uf.size(i));
        }
    }

    std::cout << ans << '\n';
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
