#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int R, G, B;
    std::cin >> R >> G >> B;

    std::vector<int> X(R);
    std::vector<int> Y(G);
    std::vector<int> Z(B);
    
    for(int i = 0; i < R; i++) {
        std::cin >> X[i];
    }

    for(int i = 0; i < G; i++) {
        std::cin >> Y[i];
    }

    for(int i = 0; i < B; i++) {
        std::cin >> Z[i];
    }

    std::sort(X.begin(), X.end(), std::greater<int>());
    std::sort(Y.begin(), Y.end(), std::greater<int>());
    std::sort(Z.begin(), Z.end(), std::greater<int>());

    std::vector<std::vector<std::vector<int64_t>>> dp(R + 1, std::vector<std::vector<int64_t>>(G + 1, std::vector<int64_t>(B + 1, 0)));
    
    int64_t ans = 0;
    for(int r = 0; r <= R; r++) {
        for(int g = 0; g <= G; g++) {
            for(int b = 0; b <= B; b++) {
                if(r && g) {
                    dp[r][g][b] = std::max(dp[r][g][b], dp[r - 1][g - 1][b] + X[r - 1] * Y[g - 1]);
                }
                if(r && b) {
                    dp[r][g][b] = std::max(dp[r][g][b], dp[r - 1][g][b - 1] + X[r - 1] * Z[b - 1]);
                }
                if(g && b) {
                    dp[r][g][b] = std::max(dp[r][g][b], dp[r][g - 1][b - 1] + Y[g - 1] * Z[b - 1]);
                }
                ans = std::max(ans, dp[r][g][b]);
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
