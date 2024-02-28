#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

int dfs(int K, std::vector<std::vector<int>>& G, int v, int p, int d, std::vector<int>& dp1, std::vector<int>& dp2) {
    if(G[v].size() == 1 && p != -1) {
        dp1[v] = 1;
        dp2[v] = 1;
        return d;
    }

    int min_d = INF;
    int max_v = 0;
    int sum = 0;
    std::vector<int> save_min_d;
    for(int nei : G[v]) {
        if(nei != p) {
            int min_dc = dfs(K, G, nei, v, d + 1, dp1, dp2);
            min_d = std::min(min_d, min_dc);
            save_min_d.push_back(min_dc);
            if(min_dc - d <= K) {
                dp2[v] += dp2[nei];
                sum += dp2[nei];
            }
        }
    }

    max_v = std::max(max_v, dp2[v]);

    int i = 0;
    for(int nei : G[v]) {
        if(nei != p) {
            int min_dc = save_min_d[i++]; 
            if(min_dc - d <= K) {
                max_v = std::max(max_v, sum - dp2[nei] + dp1[nei]);
            } else {
                max_v = std::max(max_v, sum + dp1[nei]);
            } 
        }
    }

    dp1[v] = max_v;

    return min_d;
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }
    
    std::vector<int> dp1(N, 0);
    std::vector<int> dp2(N, 0);
    dfs(K, G, 0, -1, 0, dp1, dp2);

    std::cout << dp1[0] << '\n';
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
