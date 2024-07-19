#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

struct dsu {
    int n;
    std::vector<int> p;
    std::vector<int> w;
    dsu(int _n) : n(_n), p(n, -1), w(n, 1) {}

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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    dsu uf(N);
    std::vector<std::pair<int, int>> ans;
    for(int i = N - 1; i >= 1; i--) {
        std::vector<std::vector<int>> a(i);
        for(int j = 0; j < N; j++) {
            a[A[j] % i].push_back(j); 
        } 

        bool found = false;
        for(int j = 0; j < i; j++) {
            int size = a[j].size();
            for(int p1 = 0; p1 < size; p1++) {
                for(int p2 = p1 + 1; p2 < size; p2++) {
                    int x = a[j][p1];
                    int y = a[j][p2];
                    if(!uf.same(x, y)) {
                        ans.emplace_back(x, y);
                        uf.unite(x, y);
                        found = true;
                        break;
                    }
                }
                if(found) {
                    break;
                }
            }
            if(found) {
                break;
            }
        }
    }

    std::cout << "Yes" << '\n';
    for(int i = N - 2; i >= 0; i--) {
        std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
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
