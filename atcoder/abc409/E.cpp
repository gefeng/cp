#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>

int64_t dfs(std::vector<std::vector<std::pair<int, int>>>& G, std::vector<int>& A, int v, int p, int64_t& ans) {
    int sum = A[v];
    for(auto [nei, w] : G[v]) {
        if(nei != p) {
            int64_t x = dfs(G, A, nei, v, ans);
            ans += std::abs(x) * w;
            sum += x;
        }
    }

    return sum;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<std::pair<int, int>>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V, W; 
        std::cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, W);
        G[V].emplace_back(U, W);
    }

    int64_t ans = 0;
    dfs(G, A, 0, -1, ans);

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
