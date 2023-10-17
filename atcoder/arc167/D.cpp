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

        p[y] = x;
        w[x] += w[y];
    }

    bool same(int i, int j) {
        return find(i) == find(j);
    }
};

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> pos(N, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
        pos[A[i]] = i;
    }

    dsu uf(N);
    
    for(int i = 0; i < N; i++) {
        uf.unite(i, A[i]);
    }

    std::vector<int> save_min(N, N + 1);
    for(int i = 0; i < N; i++) {
        int p = uf.find(A[i]);
        save_min[p] = std::min(save_min[p], A[i]);
    }

    std::set<int> s;
    for(int i = 0; i < N; i++) {
        if(save_min[i] != N + 1) {
            s.insert(save_min[i]);
        }
    }

    int pre_group = -1;
    for(int i = 0; i < N; i++) {
        int p = uf.find(A[i]);
        
        if(p != pre_group) {
            s.erase(save_min[p]); 
        }

        if(!s.empty() && A[i] > *s.begin()) {
            auto it = s.begin();
            int v = *it;
            int min_v = save_min[uf.find(v)];
            int new_min = std::min(save_min[p], min_v);
            s.erase(save_min[uf.find(v)]);
            uf.unite(p, v); 
            save_min[p] = new_min;

            int p1 = i;
            int p2 = pos[min_v];
            pos[A[i]] = p2;
            pos[min_v] = p1;
            std::swap(A[p1], A[p2]); 
        }

        pre_group = p;
    }

    for(int i = 0; i < N; ) {
        int j = i;
        int min_v = N + 1;
        int p = j;
        while(i < N && uf.find(A[i]) == uf.find(A[j])) {
            if(min_v > A[i]) {
                min_v = A[i];
                p = i;
            }
        
            i += 1;
        }

        if(j) {
            std::swap(A[j - 1], A[p]);
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << A[i] + 1 << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
