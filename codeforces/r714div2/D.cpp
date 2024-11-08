#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>
#include <set>
#include <functional>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

struct DSU {
    int n;
    std::vector<int> p;
    std::vector<int> w;
    DSU(int _n) : n(_n), p(n, -1), w(n, 1) {
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
};

void run_case() {
    int N, P;
    std::cin >> N >> P;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::set<int> s;
    for(int i = 0; i < N; i++) {
        s.insert(i);
    }

    std::vector<int> nodes(N);
    std::iota(nodes.begin(), nodes.end(), 0);

    std::sort(nodes.begin(), nodes.end(), [&](int x, int y) {
                return A[x] < A[y]; 
            });

    DSU uf(N);

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int w = A[nodes[i]];
        if(w < P) {
            int l = nodes[i];
            int r = nodes[i];
            int g = w;
            
            while(l - 1 >= 0) {
                g = gcd(g, A[l - 1]);
                if(g == w && !uf.same(nodes[i], l - 1)) {
                    uf.unite(nodes[i], l - 1);
                    ans += w;
                    l -= 1;
                } else {
                    break;
                }
            }

            g = w;
            while(r + 1 < N) {
                g = gcd(g, A[r + 1]);
                if(g == w && !uf.same(nodes[i], r + 1)) {
                    uf.unite(nodes[i], r + 1);
                    ans += w;
                    r += 1;
                } else {
                    break;
                }
            }
        } else {
            break;
        }
    }

    int cnt_groups = 0;
    for(int i = 0; i < N; i++) {
        if(uf.find(i) == i) {
            cnt_groups += 1;
        } 
    }

    ans += int64_t(P) * (cnt_groups - 1);

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
