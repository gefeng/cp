#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

int64_t dfs(std::vector<std::vector<int>>& G, std::vector<std::pair<int64_t, int64_t>>& A, int v, int p) {
    int64_t res = 0;
    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }

        res += dfs(G, A, nei, v);

        auto& [lu, ru] = A[v];
        auto& [lv, rv] = A[nei];
        
        if(lv > ru) {
            res += lv - ru;
            lu = ru;
        } else {
            lu = std::max(lu, lv);
        }
    }

    return res + (p == -1 ? A[v].first : 0);
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int64_t, int64_t>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
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

    std::cout << dfs(G, A, 0, -1) << '\n';
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
