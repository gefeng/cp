#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N;
    std::cin >> N;

    if(N < 10) {
        std::cout << N << '\n';
        return;
    }
    
    if(N % 10 == 0) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<std::vector<int>> dp(10, std::vector<int>(N, INF));
    std::vector<std::vector<std::pair<int, int>>> pre(10, std::vector<std::pair<int, int>>(N, {-1, -1}));
    std::queue<std::pair<int, int>> q;

    for(int i = 1; i < 10; i++) {
        dp[i][i] = 1;
        q.emplace(i, i);
    }

    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            auto [c, x] = q.front();
            q.pop();

            if(x == 0) {
                std::string ans = "";
                std::pair<int, int> now = {c, x};
                while(now.first != -1) {
                    ans.push_back(static_cast<char>(now.first + '0')); 
                    now = pre[now.first][now.second];
                }
                std::ranges::reverse(ans);
                std::cout << ans << '\n';
                return;
            }

            for(int d = c; d < 10; d++) {
                int nx = (x * 10 + d) % N;
                if(dp[d][nx] == INF) {
                    dp[d][nx] = dp[c][x] + 1;
                    pre[d][nx] = {c, x};
                    q.emplace(d, nx);
                }
            }
        }
    }

    std::cout << -1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
