#include <iostream>
#include <vector>
#include <queue>

constexpr int INF = int(2e9) + 100;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<std::pair<int, int>>> G(N);
    std::vector<int> capacity(M * 2);
    for(int i = 0; i < M; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;

        U -= 1;
        V -= 1;
        
        G[U].emplace_back(V, i); 
        G[V].emplace_back(U, i + M);
    
        capacity[i] = W;
        capacity[i + M] = 0;
    }

    int64_t flow = 0;
    while(true) {
        std::queue<std::pair<int, int>> q;
        q.emplace(0, INF);
    
        std::vector<std::pair<int, int>> pre(N, {-2, -2});
        pre[0] = {-1, -2};

        int64_t new_flow = 0;

        while(!q.empty()) {
            auto [v, f] = q.front();
            q.pop();
            
            if(v == N - 1) {
                int now = v;
                while(now != 0) {
                    auto [u, e] = pre[now];
                    capacity[e] -= f;
                    if(e < M) {
                        capacity[e + M] += f;
                    } else {
                        capacity[e - M] += f;
                    }
                    now = u;
                }
                new_flow = f;
                break;
            }

            for(auto [nei, e] : G[v]) {
                if(pre[nei].first == -2 && capacity[e]) {
                    pre[nei] = {v, e};
                    q.emplace(nei, std::min(f, capacity[e]));
                }
            }
        }

        if(new_flow == 0) {
            break;
        }

        flow += new_flow;
    }

    std::cout << flow << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
