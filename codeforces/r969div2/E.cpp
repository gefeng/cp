#include <iostream>
#include <utility>
#include <cassert> 
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void dfs(std::vector<std::vector<int>>& G, int v, std::vector<int>& size) {
    size[v] = 1;
    
    for(int nei : G[v]) {
        dfs(G, nei, size);
        size[v] += size[nei];
    }
}

void run_case() {
    int N;
    int64_t W;
    std::cin >> N >> W;

    std::vector<std::vector<int>> G(N);
    std::vector<int> P(N, -1);
    for(int i = 0; i < N - 1; i++) {
        std::cin >> P[i + 1];
        P[i + 1] -= 1;
        G[P[i + 1]].push_back(i + 1);
    }

    std::vector<int> size(N, 0);
    dfs(G, 0, size);
    
    std::vector<std::set<int>> path(N);
    std::vector<int64_t> path_sum(N, 0);
    for(int i = 1; i < N; i++) {
        path[i - 1].insert(i);
        path[i + size[i] - 1].insert(i);
    }

    int64_t ans = W * N;
    int64_t cnt = N;
    int64_t sum_determined = 0;
    for(int i = 0; i < N - 1; i++) {
        int V;
        int64_t X;
        std::cin >> V >> X;
        V -= 1;
        
        int v = V - 1; 
        path[v].erase(V);
        if(path[v].empty()) {
            cnt -= 1;
            ans -= W - sum_determined + path_sum[v];
            ans += path_sum[v] + X;
        } else {
            ans += X;
        }
        path_sum[v] += X;

        v = V + size[V] - 1;
        path[v].erase(V);
        if(path[v].empty()) {
            cnt -= 1;
            ans -= W - sum_determined + path_sum[v];
            ans += path_sum[v] + X;
        } else {
            ans += X;
        }
        path_sum[v] += X;

        sum_determined += X;

        ans -= cnt * X;
        std::cout << ans << " \n"[i == N - 2];
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
