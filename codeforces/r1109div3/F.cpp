#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>

constexpr int INF = static_cast<int>(2e9) + 10;

std::tuple<int, int, int> dfs(std::vector<std::vector<int>>& G, std::vector<int>& A, int v) {
    if(G[v].size() == 0) {
        return {A[v], A[v], 1};
    }

    std::vector<std::pair<int, int>> c;
    for(int u : G[v]) {
        auto [l, r, x] = dfs(G, A, u);
        c.emplace_back(l, r);
        if(!x) {
            return {-1, -1, 0};
        }
    }

    int s = -1;
    int n = c.size();
    int min_v = INF;
    int max_v = 0;
    int res = 1;
    for(int i = 0; i < n; i++) {
        auto [l, r] = c[i];
        if(l < min_v) {
            min_v = l;
            s = i;
        }
    }

    for(int i = s, j = 0; j < n; i = (i + 1) % n, j++) {
        auto [l, r] = c[i];
        max_v = std::max(max_v, r);
        if(i != s) {
            int p = (i - 1 + n) % n;
            if(c[p].second + 1 != l) {
                res = 0;  
                break;
            }
        }
    }

    if(!res) {
        return {-1, -1, 0};
    } else {
        return {min_v, max_v, res};
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> G(N);
    for(int i = 1; i < N; i++) {
        int P;
        std::cin >> P;
        P--;
        G[P].push_back(i);
    }

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto [l, r, ans] = dfs(G, A, 0);
    
    std::cout << (ans ? "YES" : "NO") << '\n';
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
