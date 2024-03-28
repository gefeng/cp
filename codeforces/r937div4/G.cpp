#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<std::string, std::string>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::vector<std::vector<int>> g(N);
    for(int j = 0; j < N; j++) {
        for(int k = j + 1; k < N; k++) {
            if(A[j].first == A[k].first || A[j].second == A[k].second) {
                g[j].push_back(k);
                g[k].push_back(j);
            }
        }
    } 

    int ans = N - 1;
    std::vector<std::vector<int>> dp(1 << N, std::vector<int>(N, 0));
    for(int j = 0; j < N; j++) {
        dp[1 << j][j] = 1;
    } 

    for(int i = 0; i < (1 << N); i++) {
        for(int j = 0; j < N; j++) {
            if((i & (1 << j)) && dp[i][j]) {
                for(int k : g[j]) {
                    if(i & (1 << k)) {
                        continue;
                    }

                    dp[i | (1 << k)][k] = 1;
                    ans = std::min(ans, N - __builtin_popcount(i) - 1);
                }
            }
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
