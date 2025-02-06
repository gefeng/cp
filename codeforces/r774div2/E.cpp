#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_set>

constexpr int LOG = 20;
constexpr int MAX = int(1e6);

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> dp(LOG + 1, 0);
    std::vector<int> seen(MAX * LOG + 10, 0);
    
    for(int i = 1; i <= LOG; i++) {
        int now = i;
        int cnt = 0;
        for(int j = 0; j < M; j++) {
            if(!seen[now]) {
                seen[now] = 1;
                cnt += 1;
            }
            now += i;
        } 
        dp[i] = dp[i - 1] + cnt;
    }

    std::vector<int> vis(N + 1, 0);
    int64_t ans = 1;
    for(int i = 2; i <= N; i++) {
        if(vis[i]) {
            continue;
        }

        int64_t now = i;
        int cnt = 0;
        while(now <= N) {
            vis[now] = 1;
            cnt += 1;
            now *= i;
        }

        ans += dp[cnt];
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
