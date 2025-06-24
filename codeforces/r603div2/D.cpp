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

    int size() {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(p[i] < 0) {
                cnt += 1;
            }
        } 
        return cnt;
    }
};

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    dsu uf(N);
    for(char c = 'a'; c <= 'z'; c++) {
        int pre = -1;
        for(int i = 0; i < N; i++) {
            if(A[i].find(c) != std::string::npos) {
                if(pre != -1) {
                    uf.unite(pre, i);
                } else {
                    pre = i;
                }
            }
        } 
    }

    std::cout << uf.size() << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
