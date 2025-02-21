#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void dfs_1(std::vector<std::vector<int>>& G, int v, int p, int d, std::vector<int>& size, std::vector<int64_t>& depth) {
    depth[d] += 1;
    size[v] = 1;
    
    for(int nei : G[v]) {
        if(nei != p) {
            dfs_1(G, nei, v, d + 1, size, depth);
            size[v] += size[nei];
        }
    }
}

void dfs_2(std::vector<std::vector<int>>& G, int v, int p, int d, std::vector<int>& size, std::vector<int64_t>& depth, 
        std::vector<int64_t>& f) {
    if(p != -1) {
        int64_t cnt_deeper = depth[d - 1] - size[p] + 1;
        f[v] = f[p] + 2 * cnt_deeper;
        f[v] += size[p] - size[v] - 1;
    }

    for(int nei : G[v]) {
        if(nei != p) {
            dfs_2(G, nei, v, d + 1, size, depth, f);
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

    std::vector<int> size(N, 0);
    std::vector<int64_t> depth(N, 0);
    std::vector<int64_t> f(N, 0);

    dfs_1(G, 0, -1, 0, size, depth);
    
    int64_t sum = depth[N - 1];
    depth[N - 1] = 0;
    for(int i = N - 2; i >= 0; i--) {
        int64_t val = depth[i];
        depth[i] = sum;
        sum += val;
    }

    dfs_2(G, 0, -1, 0, size, depth, f);

    int64_t ans = std::accumulate(f.begin(), f.end(), int64_t(0));
    ans /= 2;

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
