#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <functional>

void dfs1(std::vector<std::vector<int>>& G, int v, int p, int depth, std::vector<int>& size, std::vector<int>& sum) {
    for(int nei : G[v]) {
        if(nei != p) {
            dfs1(G, nei, v, depth + 1, size, sum);
            size[v] += size[nei];
        }
    }
    
    size[v] += 1;
    sum[depth] += size[v];
}

void dfs2(std::vector<std::vector<int>>& G, int v, int p, int d, std::vector<int>& max_d) {
    if(p != -1 && G[v].size() == 1) {
        max_d[v] = d;
    }

    for(int nei : G[v]) {
        if(nei != p) {
            dfs2(G, nei, v, d + 1, max_d);
            max_d[v] = std::max(max_d[nei], max_d[v]);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int> sum1(N + 1, 0);
    std::vector<int> sum2(N + 1, 0);
    std::vector<int> size(N, 0);
    std::vector<int> max_d(N, 0);
    
    dfs1(G, 0, -1, 0, size, sum1); 
    dfs2(G, 0, -1, 0, max_d);

    int n = 0;
    for(int i = 0; i < N; i++) {
        sum2[max_d[i]] += 1;
        n = std::max(n, max_d[i]);
    }

    for(int i = 1; i <= n; i++) {
        sum2[i] += sum2[i - 1];
    }
    
    int64_t ans = N;
    for(int d = 1; d <= n; d++) {
        int64_t cnt = sum1[d + 1] + sum2[d - 1];
        ans = std::min(ans, cnt);
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
