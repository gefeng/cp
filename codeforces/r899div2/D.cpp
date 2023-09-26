#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector> 

void dfs1(int N, std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, 
        std::vector<int64_t>& save_size, std::vector<int64_t>& save_cost) {
    for(int nei : G[v]) {
        if(nei != p) {
            dfs1(N, G, A, nei, v, save_size, save_cost);
            save_size[v] += save_size[nei];
            save_cost[v] += save_cost[nei];
        }
    }

    save_size[v] += 1;
    save_cost[v] += p == -1 ? 0 : (A[v] ^ A[p]) * save_size[v];
}

void dfs2(int N, std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, 
        std::vector<int64_t>& save_size, std::vector<int64_t>& save_cost, std::vector<int64_t>& ans) {
    if(p == -1) {
        ans[v] = save_cost[v];
    } else {
        ans[v] = ans[p] + (save_size[0] - save_size[v]) * (A[p] ^ A[v]) - save_size[v] * (A[v] ^ A[p]);
    }

    for(int nei : G[v]) {
        if(nei != p) {
            dfs2(N, G, A, nei, v, save_size, save_cost, ans);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int64_t> save_size(N, 0);
    std::vector<int64_t> save_cost(N, 0);
    std::vector<int64_t> ans(N, 0);
    
    dfs1(N, G, A, 0, -1, save_size, save_cost);
    dfs2(N, G, A, 0, -1, save_size, save_cost, ans);

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
