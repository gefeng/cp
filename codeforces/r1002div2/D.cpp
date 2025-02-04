#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int INF = int(2e9);

struct S {
    int v;
    int u;
    int cost;
    S(int _v, int _u, int _cost) : v(_v), u(_u), cost(_cost) {}

    friend bool operator< (const S& lhs, const S& rhs) {
        return lhs.cost > rhs.cost;
    }
};

void run_case() {
    int N, S_1, S_2;
    std::cin >> N >> S_1 >> S_2;
    
    S_1 -= 1;
    S_2 -= 1;

    std::vector<std::vector<int>> G_1(N);
    std::vector<std::vector<int>> G_2(N);

    int M_1;
    std::cin >> M_1;
    for(int i = 0; i < M_1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G_1[U].push_back(V);
        G_1[V].push_back(U);
    }

    int M_2;
    std::cin >> M_2;
    for(int i = 0; i < M_2; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G_2[U].push_back(V);
        G_2[V].push_back(U);
    }

    auto cmp = [](const auto& x, const auto& y) {
        return x.cost > y.cost;
    };

    std::priority_queue<S> pq;
    std::vector<std::vector<int>> best(N, std::vector<int>(N, INF));
    
    pq.emplace(S_1, S_2, 0);
    best[S_1][S_2] = 0;

    while(!pq.empty()) {
        const S& now = pq.top();
        int cost = now.cost;
        int v = now.v;
        int u = now.u;
        pq.pop();
        
        if(best[v][u] != cost) {
            continue;
        }

        for(int n_v : G_1[v]) {
            for(int n_u : G_2[u]) {
                int n_cost = cost + std::abs(n_v - n_u);
                if(best[n_v][n_u] > n_cost) {
                    best[n_v][n_u] = n_cost;
                    pq.emplace(n_v, n_u, n_cost);
                }
            }
        }
    }

    int ans = INF;
    for(int v = 0; v < N; v++) {
        if(best[v][v] != INF) {
            std::vector<int> seen(N, 0);
            for(int u : G_1[v]) {
                seen[u] = 1;
            }

            for(int u : G_2[v]) {
                if(seen[u]) {
                    ans = std::min(best[v][v], ans);  
                }
            }
        }
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
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
