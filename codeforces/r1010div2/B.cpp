#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <tuple>

constexpr int INF = int(2e9);
constexpr int MAX = 40;

void run_case() {
    int X, N, M;
    std::cin >> X >> N >> M;

    N = std::min(N, MAX);
    M = std::min(M, MAX);

    std::vector<int> dp(M + 1, 0); 
    dp[0] = X;
    for(int i = 1; i <= M; i++) {
        dp[i] = (dp[i - 1] + 1) / 2;
    }

    int min_v = INF;
    int max_v = 0;
    for(int i = 0; i <= M; i++) {
        int v = dp[i];
        int n = N;
        while(v && n) {
            v /= 2;
            n -= 1;
        }

        if(v) {
            int m = M - i;
            while(v && m) {
                v = (v + 1) / 2;
                m -= 1;
            }
        }
        
        min_v = std::min(min_v, v);
        max_v = std::max(max_v, v);
    }

    std::cout << min_v << ' ' << max_v << '\n';
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
