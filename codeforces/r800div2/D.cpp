#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

std::pair<int, int> dfs(std::vector<std::vector<int>>& G, std::vector<std::pair<int, int>>& A, int v) {
    if(G[v].empty()) {
        return {1, A[v].second};
    }

    int cnt = 0;
    int64_t min_v = A[v].second;
    int64_t sum = 0;
    for(int nei : G[v]) {
        auto [c, v] = dfs(G, A, nei);
        cnt += c;
        sum += v;
    }

    min_v = std::min(min_v, sum);

    if(min_v < A[v].first) {
        cnt += 1;
        min_v = A[v].second;
    }
    return {cnt, static_cast<int>(min_v)};
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> G(N);
    for(int i = 1; i < N; i++) {
        int P;
        std::cin >> P;
        P -= 1;
        G[P].push_back(i);
    }

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::cout << dfs(G, A, 0).first << '\n';
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
