#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int64_t dfs(std::vector<std::vector<int>>& G, int v, std::vector<int>& save_size) {
    int64_t res = 0;
    for(int nei : G[v]) {
        res += dfs(G, nei, save_size);
        save_size[v] += save_size[nei];
    }

    int m = G[v].size();
    if(m) {
        int n = save_size[v]; 
        std::vector<int64_t> dp(n + 1, 0);
        int sum = save_size[G[v].front()];
        for(int i = 1; i < m; i++) {
            int sz = save_size[G[v][i]];
            for(int j = sum; j >= 0; j--) {
                for(int k = sz; k >= 0; k--) {
                    dp[k + j] = std::max(dp[k + j], dp[j] + (int64_t)k * (sum - j) + (int64_t)j * (sz - k));
                }
            }
            sum += sz;
        }

        res += *std::max_element(dp.begin(), dp.end());
    }

    save_size[v] += 1;

    return res;
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

    std::vector<int> save_size(N, 0);
    std::cout << dfs(G, 0, save_size) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    run_case();
}
