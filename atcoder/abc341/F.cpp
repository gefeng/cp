#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 5000;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;

        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int> W(N);
    std::vector<int> A(N);
    std::vector<std::pair<int, int>> wp(N);
    for(int i = 0; i < N; i++) {
        std::cin >> W[i];
        wp[i] = {W[i], i};
    }

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(wp.begin(), wp.end());
    
    std::vector<int64_t> dp(N, 0);

    for(int i = 0; i < N; i++) {
        auto [w, v] = wp[i];
        
        std::vector<int> a;
        for(int nei : G[v]) {
            if(W[nei] < w) {
                a.push_back(nei); 
            } 
        }

        dp[v] = 1;
        if(a.empty()) {
            continue;
        }

        int n = a.size();
        std::vector<std::vector<int64_t>> save(n + 1, std::vector<int64_t>(w, -1));
        save[0][0] = 1;

        for(int j = 1; j <= n; j++) {
            int u = a[j - 1];
            for(int sum = 0; sum < w; sum++) {
                save[j][sum] = std::max(save[j][sum], save[j - 1][sum]);

                int x = sum - W[u];
                if(x >= 0 && save[j - 1][x] != -1) {
                    save[j][sum] = std::max(save[j][sum], save[j - 1][x] + dp[u]);
                }
            }
        }
        
        for(int sum = 0; sum < w; sum++) {
            dp[v] = std::max(dp[v], save[n][sum]);
        }
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        ans += dp[i] * A[i]; 
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
