#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9);
constexpr int MAX = 1000;

std::vector<int> dp(MAX + 1, INF);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> B(N);
    std::vector<int> C(N);

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> C[i];
    }

    int m = std::min(K, 12 * N);
    std::vector<int64_t> ds(m + 1, 0);
    
    for(int i = 0; i < N; i++) {
        std::vector<int64_t> nds(ds);
        int k = dp[B[i]];
        
        for(int j = 0; j <= m; j++) {
            if(j + k <= m) {
                nds[j + k] = std::max(nds[j + k], ds[j] + C[i]);
            }
        }

        ds = std::move(nds);
    }

    int64_t ans = 0;
    for(int i = 0; i <= m; i++) {
        ans = std::max(ans, ds[i]);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    dp[1] = 0;
    std::vector<int> now;
    now.push_back(1);
    
    while(!now.empty()) {
        std::vector<int> nxt;
        for(int x : now) {
            for(int y = 1; y <= x; y++) {
                int z = x + x / y;
                if(z <= MAX && dp[x] + 1 < dp[z]) {
                    dp[z] = dp[x] + 1;
                    nxt.push_back(z);
                }
            } 
        }
        now = std::move(nxt);
    }

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
