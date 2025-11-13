#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>
#include <ranges>
#include <set>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::vector<std::pair<int, int>> E(M);
    std::vector<int> degree(N, 0);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        degree[U] += 1;
        degree[V] += 1;
        E[i] = {U, V};
    } 

    if(M % 2 == 0) {
        std::cout << 0 << '\n';
        return;
    }

    int ans = std::accumulate(A.begin(), A.end(), 0);

    for(auto [u, v] : E) {
        if(degree[u] % 2 == 1) {
            ans = std::min(ans, A[u]);
        }
        if(degree[v] % 2 == 1) {
            ans = std::min(ans, A[v]);
        }
        if(degree[u] % 2 == 0 && degree[v] % 2 == 0) {
            ans = std::min(ans, A[u] + A[v]);
        }
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
