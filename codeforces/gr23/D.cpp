#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

int64_t dfs(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int k, std::map<std::pair<int, int>, int64_t>& memo) {
    if(k == 0) {
        return 0;
    }

    int c = G[v].size();
    if(c == 0) {
        return static_cast<int64_t>(A[v]) * k;
    }

    if(memo.find({v, k}) != memo.end()) {
        return memo[{v, k}];
    }
    
    int64_t res = static_cast<int64_t>(A[v]) * k;
    
    if(k % c == 0) {
        for(int u : G[v]) {
            res += dfs(G, A, u, k / c, memo);
        }
    } else {
        int r = k % c;
        std::vector<std::pair<int64_t, int64_t>> a;
        for(int u : G[v]) {
            int64_t x = dfs(G, A, u, k / c, memo);
            int64_t y = dfs(G, A, u, k / c + 1, memo);
            a.emplace_back(x, y);
        }
        
        std::ranges::sort(a, [&](const auto& x, const auto& y) {
                    return x.second - x.first > y.second - y.first;
                });

        for(int i = 0; i < c; i++) {
            if(i < r) {
                res += a[i].second;
            } else {
                res += a[i].first;
            }
        }
    }
    return memo[{v, k}] = res;
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> G(N);
    for(int i = 1; i < N; i++) {
        int P;
        std::cin >> P;
        G[P - 1].push_back(i);
    }

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<std::pair<int, int>, int64_t> memo;
    int64_t ans = dfs(G, A, 0, K, memo);

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
