#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int d, std::vector<int>& is_covered) {
    d = std::max(d, A[v]);
    
    if(d) {
        is_covered[v] = 1;
    }

    for(int nei : G[v]) {
        dfs(G, A, nei, std::max(0, d - 1), is_covered);
    }
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N);
    for(int i = 1; i < N; i++) {
        int P;
        std::cin >> P;
        P -= 1;
        G[P].push_back(i);
    }

    std::vector<int> A(N, 0);
    for(int i = 0; i < M; i++) {
        int P, X;
        std::cin >> P >> X;
        P -= 1;
        A[P] = std::max(A[P], X + 1);
    }

    std::vector<int> is_covered(N, 0);
    dfs(G, A, 0, 0, is_covered);

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(is_covered[i]) {
            ans += 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
