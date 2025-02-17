#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int64_t dfs(std::vector<std::vector<int>>& G, std::vector<int64_t>& A, int v, std::vector<int64_t>& sum, std::vector<int64_t>& leaf) {
    sum[v] += A[v];
    if(G[v].empty()) {
        leaf[v] = 1;
        return A[v];
    }
    
    int64_t max_v = 0;
    for(int nei : G[v]) {
        max_v = std::max(max_v, dfs(G, A, nei, sum, leaf));
        sum[v] += sum[nei];
        leaf[v] += leaf[nei];
    }

    max_v = std::max(max_v, (sum[v] + leaf[v] - 1) / leaf[v]);

    return max_v;
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> G(N);
    std::vector<int64_t> A(N);

    for(int i = 1; i < N; i++) {
        int P;
        std::cin >> P;
        P -= 1;
        G[P].push_back(i);
    }

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> sum(N, 0);
    std::vector<int64_t> leaf(N, 0);
    std::cout << dfs(G, A, 0, sum, leaf) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
