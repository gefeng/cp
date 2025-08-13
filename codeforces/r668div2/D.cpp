#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int INF = static_cast<int>(2e9);

void run_case() {
    int N, A, B, DA, DB;
    std::cin >> N >> A >> B >> DA >> DB;
    
    A -= 1;
    B -= 1;
    
    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int> dist(N, INF);
    std::queue<int> q;

    q.push(B);
    dist[B] = 0;
    int max_d = 0;    
    int max_v = B;
    while(!q.empty()) {
        int v = q.front();
        q.pop();

        if(dist[v] > max_d) {
            max_d = dist[v];
            max_v = v;
        }
        
        for(int nei : G[v]) {
            if(dist[nei] == INF) {
                dist[nei] = dist[v] + 1;
                q.push(nei);
            }
        }
    }

    if(DA >= dist[A] || DB <= 2 * DA) {
        std::cout << "Alice" << '\n';
        return;
    }

    q.push(max_v);
    max_d = 0;
    dist.assign(N, INF);
    dist[max_v] = 0;

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        max_d = std::max(max_d, dist[v]);

        for(int nei : G[v]) {
            if(dist[nei] == INF) {
                dist[nei] = dist[v] + 1;
                q.push(nei);
            }
        }
    }

    std::cout << (max_d <= 2 * DA ? "Alice" : "Bob") << '\n';
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
