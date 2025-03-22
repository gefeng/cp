#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int H, W;
    std::cin >> H >> W;
    
    std::vector<int> A(H, 0);
    for(int i = 0; i < H; i++) {
        std::string S;
        std::cin >> S;
        
        for(int j = S.size() - 1; j >= 0; j--) {
            if(S[j] == '1') {
                A[i] |= 1 << (S.size() - 1 - j);
            }
        }
    }
    
    std::vector<std::vector<std::vector<int>>> dp(W + 1, std::vector<std::vector<int>>(W + 1, std::vector<int>(1 << W, 0)));
    for(int i = 0; i < H; i++) {
        dp[0][0][A[i]] += 1;
    } 

    for(int i = 1; i <= W; i++) {
        for(int j = 0; j <= W; j++) {
            for(int x = 0; x < (1 << W); x++) {
                dp[i][j][x] = dp[i - 1][j][x];
                if(j - 1 >= 0) {
                    dp[i][j][x] += dp[i - 1][j - 1][x ^ (1 << (i - 1))];
                }
            }
        }
    }

    int ans = H * W;
    for(int x = 0; x < (1 << W); x++) {
        int cnt = 0;
        for(int i = 0; i <= W; i++) {
            cnt += std::min(i, W - i) * dp[W][i][x];
        }
        ans = std::min(ans, cnt);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
