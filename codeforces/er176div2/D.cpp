#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int64_t INF = int64_t(4e18);
constexpr int MAX = 60;

std::vector<std::vector<int64_t>> dp(MAX + 1, std::vector<int64_t>(MAX + 1, INF));

void run_case() {
    int64_t X, Y;
    std::cin >> X >> Y;

    if(X == Y) {
        std::cout << 0 << '\n';
        return;
    }

    int64_t ans = INF;
    
    std::map<int64_t, std::vector<int>> m;
    for(int i = 0; i <= MAX; i++) {
        m[X / (int64_t(1) << i)].push_back(i);
    }    
    
    for(int i = 0; i <= MAX; i++) {
        int64_t y = Y / (int64_t(1) << i);
        
        if(m.find(y) == m.end()) {
            continue;
        }

        for(int j : m[y]) {
            ans = std::min(ans, dp[j][i]);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    dp[0][0] = 0;
    for(int i = 1; i <= MAX; i++) {
        std::vector<std::vector<int64_t>> ndp(dp);
        
        for(int j = 0; j <= MAX; j++) {
            for(int k = 0; k <= MAX; k++) {
                if(j - i >= 0 && dp[j - i][k] != INF) {
                    ndp[j][k] = std::min(ndp[j][k], dp[j - i][k] + (int64_t(1) << i));
                }
                if(k - i >= 0 && dp[j][k - i] != INF) {
                    ndp[j][k] = std::min(ndp[j][k], dp[j][k - i] + (int64_t(1) << i));
                }
            }
        }

        std::swap(dp, ndp);
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
