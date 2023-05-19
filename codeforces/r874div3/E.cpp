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
};

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    dsu uf(N);
    for(int i = 0; i < N; i++) {
        uf.unite(i, A[i]); 
    } 

    std::vector<bool> have_pair(N, false);
    for(int i = 0; i < N; i++) {
        if(A[A[i]] == i) {
            have_pair[uf.find(i)] = true;
        }
    }

    int ans_min = 0;
    int ans_max = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(uf.find(i) == i) {
            if(have_pair[i]) {
                cnt += 1;
            }
            ans_max += 1;
        } 
    }

    ans_min = ans_max;

    if(cnt) {
        ans_min -= cnt;
        ans_min += 1;
    }

    std::cout << ans_min << ' ' << ans_max << '\n';
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
