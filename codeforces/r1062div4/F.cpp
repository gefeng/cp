#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs1(std::vector<std::vector<int>>& G, int K, int v, int p, std::vector<int>& size, std::vector<int>& dp1, std::vector<int>& inclusive) {
    size[v] = 1;    
    for(int nei : G[v]) {
        if(nei != p) {
            dfs1(G, K, nei, v, size, dp1, inclusive);
            size[v] += size[nei];
            dp1[v] += dp1[nei];
        }
    }
    
    if(size[v] >= K) {
        dp1[v] += 1;
        inclusive[v] = 1;
    }
}

void dfs2(std::vector<std::vector<int>>& G, int K, int v, int p, std::vector<int>& size, 
        std::vector<int>& dp1, std::vector<int>& dp2, std::vector<int>& inclusive) {
    dp2[v] = dp1[v];
    if(p != -1) {
        if(!inclusive[v]) {
            if(size[0] >= K) {
                dp2[v] += 1;
                inclusive[v] = 1;
            }
        }
        if(inclusive[p]) {
            if(size[0] - size[v] >= K) {
                dp2[v] += dp2[p] - dp1[v];
            } else {
                dp2[v] += dp2[p] - dp1[v] - 1;
            }
        } else {
            dp2[v] += dp2[p] - dp1[v];
        }
    }

    for(int nei : G[v]) {
        if(nei != p) {
            dfs2(G, K, nei, v, size, dp1, dp2, inclusive);
        }
    }
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

    std::vector<int> size(N, 0);
    std::vector<int> dp1(N, 0);
    std::vector<int> dp2(N, 0);
    std::vector<int> inclusive(N, 0);
    dfs1(G, K, 0, -1, size, dp1, inclusive);
    dfs2(G, K, 0, -1, size, dp1, dp2, inclusive);

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        ans += dp2[i];
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
