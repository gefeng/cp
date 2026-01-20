#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void dfs(std::vector<std::vector<std::pair<int, int>>>& G, int v, int par, std::vector<int>& p, std::vector<int>& w) {
    for(auto [nei, x] : G[v]) {
        if(nei != par) {
            p[nei] = v;
            w[nei] = x;
            dfs(G, nei, v, p, w);
        }
    }
}

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<std::pair<int, int>>> G(N);
    std::vector<int> p(N, -1);
    std::vector<int> w(N, 0);
    int64_t sum = 0;
    for(int i = 0; i < N - 1; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, W);
        G[V].emplace_back(U, W);
        if(A[U] != A[V]) {
            sum += W;
        }
    }

    dfs(G, 0, -1, p, w);

    std::vector<std::map<int, int64_t>> m(N);
    for(int i = 0; i < N; i++) {
        for(auto [v, x] : G[i]) {
            if(v != p[i]) {
                m[i][A[v]] += x;
            } 
        }
    }
    

    for(int i = 0; i < Q; i++) {
        int V, X;
        std::cin >> V >> X;
        V -= 1;

        if(A[V] == X) {
            std::cout << sum << '\n';
            continue;
        }
        
        if(V) {
            if(A[V] != A[p[V]]) {
                sum -= w[V]; 
            }
            m[p[V]][A[V]] -= w[V];
        }

        if(m[V].find(A[V]) != m[V].end()) {
            sum += m[V][A[V]];
        }


        A[V] = X;

        if(V) {
            if(A[V] != A[p[V]]) {
                sum += w[V];
            }
            m[p[V]][A[V]] += w[V];
        }

        if(m[V].find(A[V]) != m[V].end()) {
            sum -= m[V][A[V]];
        }

        std::cout << sum << '\n';
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
