#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

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

    int size(int i) {
        return w_[find(i)];
    }
};

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> A(M);
    std::vector<int> col(N + 1, -1);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i].first >> A[i].second;
        col[A[i].second] = i;
    }

    dsu uf(M);
    for(int i = 0; i < M; i++) {
        auto [r, c] = A[i];
        if(col[r] != -1) {
            uf.unite(col[r], i);
        }
    }

    int ans = 0;
    std::vector<std::vector<int>> groups(M);
    for(int i = 0; i < M; i++) {
        groups[uf.find(i)].push_back(i);
    }

    for(int i = 0; i < M; i++) {
        if(groups[i].empty()) {
            continue;
        }

        if(groups[i].size() == 1) {
            int j = groups[i].front();
            ans += A[j].first == A[j].second ? 0 : 1;
            continue;
        }
        
        ans += groups[i].size() + 1;
        for(int j : groups[i]) {
            auto [r, c] = A[j]; 
            if(col[r] == -1) {
                ans -= 1;
                break;
            }
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
