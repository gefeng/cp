#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

LL dfs1(std::vector<std::vector<int>>& G, int K, int v, int p, std::vector<std::pair<LL, LL>>& save_max) {
    LL max1 = 0LL;
    LL max2 = 0LL;

    for(int nei : G[v]) {
        if(nei != p) {
            LL ret = dfs1(G, K, nei, v, save_max);
            if(ret > max1) {
                max2 = max1;
                max1 = ret;
            } else if(ret > max2) {
                max2 = ret;
            }
        }
    }

    save_max[v].first = max1;
    save_max[v].second = max2;
    
    return max1 + K;
}

void dfs2(std::vector<std::vector<int>>& G, int K, int C, int v, int p, LL cost,  
        std::vector<std::pair<LL, LL>>& save_max, std::vector<LL>& profit) {

    if(p == -1) {
        profit[v] = save_max[v].first;
    } else {
        LL p_max = save_max[p].first;
        LL v_max = save_max[v].first;
        if(p_max == v_max + K) {
            p_max = save_max[p].second;
        }

        p_max += K;
        
        profit[v] = std::max(p_max, v_max) - cost;

        if(p_max > v_max) {
            save_max[v].second = save_max[v].first;
            save_max[v].first = p_max;
        } else if(p_max > save_max[v].second) {
            save_max[v].second = p_max;
        }
    }

    for(int nei : G[v]) {
        if(nei != p) {
            dfs2(G, K, C, nei, v, cost + C, save_max, profit);
        }
    }
}

void run_case() {
    int N, K, C;
    std::cin >> N >> K >> C;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<std::pair<LL, LL>> save_max(N);
     
    dfs1(G, K, 0, -1, save_max);

    std::vector<LL> profit(N);
    dfs2(G, K, C, 0, -1, 0LL, save_max, profit);

    LL ans = 0LL;
    for(int i = 0; i < N; i++) {
        ans = std::max(ans, profit[i]);
    }

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
