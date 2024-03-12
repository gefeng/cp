#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int64_t INF = (int64_t)1e18;

void run_case() {
    int N, M, K, D;
    std::cin >> N >> M >> K >> D;

    std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<int64_t> cost(N);
    for(int i = 0; i < N; i++) {
        std::vector<int64_t> dp(M, INF);
        std::multiset<int64_t> s;
        dp[0] = 1;
        s.insert(1);

        for(int l = 0, r = 1; r < M; r++) {
            if(r - l - 1 > D) {
                s.erase(s.find(dp[l++]));
            }
            
            dp[r] = std::min(dp[r], *s.begin() + A[i][r] + 1);

            s.insert(dp[r]);
        }
        cost[i] = dp[M - 1];
    }

    int64_t ans = INF;
    int64_t sum = 0;
    for(int l = 0, r = 0; r < N; r++) {
        sum += cost[r]; 
        if(r - l + 1 > K) {
            sum -= cost[l++];
        }

        if(r - l + 1 == K) {
            ans = std::min(ans, sum);
        }
    }

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
