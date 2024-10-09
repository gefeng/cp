#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int64_t INF = int64_t(1e18);

void run_case() {
    int N, M, P;
    std::cin >> N >> M >> P;

    std::vector<int> A(P);
    for(int i = 0; i < P; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }
    
    std::vector<std::vector<std::pair<int, int>>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, W);
        G[V].emplace_back(U, W);
    }

    std::vector<std::vector<int>> max_latency(N, std::vector<int>(N, int(1e9)));    

    auto dijkstra = [&](int st) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.emplace(0, st);
        max_latency[st][st] = 0;
        
        while(!pq.empty()) {
            auto [l, v] = pq.top();
            pq.pop();
            
            if(l != max_latency[st][v]) {
                continue;
            }

            for(auto [nei, w] : G[v]) {
                int nl = std::max(w, l);
                if(max_latency[st][nei] > nl) {
                    max_latency[st][nei] = nl;
                    pq.emplace(nl, nei);
                }
            }
        }
    };

    for(int i = 0; i < N; i++) {
        dijkstra(i);
    }

    std::vector<int> is_server(N, 0);
    std::vector<int> best_latency(N, int(1e9));
    for(int k = 1; k <= N; k++) {
        int64_t res = INF;
        if(k < P) {
            int which = -1;
            for(int s : A) {
                if(!is_server[s]) {
                    int64_t sum = 0;
                    for(int t : A) {
                        sum += std::min(best_latency[t], max_latency[t][s]);
                    }
                    if(sum < res) {
                        res = sum;
                        which = s;
                    }
                }
            }

            is_server[which] = 1;
            for(int t : A) {
                best_latency[t] = std::min(best_latency[t], max_latency[t][which]); 
            }
        } else {
            res = 0;
        }
        
        std::cout << res << " \n"[k == N];
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
