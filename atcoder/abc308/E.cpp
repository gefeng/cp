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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::string S;
    std::cin >> S;

    std::vector<std::vector<int>> dp(N, std::vector<int>(1 << 3, 0));
    std::vector<int> cur(1 << 3, 0);
    
    for(int i = 0; i < N; i++) {
        if(S[i] == 'M') {
            cur[1 << A[i]] += 1;
        }
        if(S[i] == 'E') {
            for(int j = 0; j < (1 << 3); j++) {
                dp[i][j | (1 << A[i])] += cur[j];
            }
        }
    }

    cur = std::vector<int>(1 << 3, 0);
    int64_t ans = 0;
    for(int i = N - 1; i >= 0; i--) {
        if(S[i] == 'X') {
            cur[1 << A[i]] += 1;
        }
        if(S[i] == 'E') {
            for(int j = 0; j < (1 << 3); j++) {
                for(int k = 0; k < (1 << 3); k++) {
                    int m = j | k;
                    if((m & 1) == 0) {
                        continue;
                    }
                    if((m & 2) == 0) {
                        ans += (int64_t)dp[i][j] * cur[k]; 
                        continue;
                    }
                    if((m & 4) == 0) {
                        ans += (int64_t)2 * dp[i][j] * cur[k];
                        continue;
                    }

                    ans += (int64_t)3 * dp[i][j] * cur[k];
                }
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
