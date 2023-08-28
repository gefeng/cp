#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = (int)1e5;
constexpr int64_t INF = (int64_t)1e18;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    std::vector<int> b(N);
    for(int i = 0; i < N; i++) {
        int X, Y;
        std::cin >> X >> Y;

        a[i] = X > Y ? 0 : (Y - X + 1) / 2;
        std::cin >> b[i];
    }

    std::vector<int64_t> dp(MAX * 2 + 1, -1);
    dp[MAX] = 0;
    for(int i = 0; i < N; i++) {
        std::vector<int64_t> ndp(MAX * 2 + 1, -1);

        if(a[i] == 0) {
            for(int j = -MAX; j <= MAX; j++) {
                int nj = j + b[i] + MAX;
                if(nj <= MAX * 2 && dp[j + MAX] != -1) {
                    ndp[nj] = ndp[nj] == -1 ? dp[j + MAX] : std::min(ndp[nj], dp[j + MAX]);
                }
            }
        } else {
            for(int j = -MAX; j <= MAX; j++) {
                int nj = j - b[i] + MAX;
                if(nj <= MAX * 2 && dp[j + MAX] != -1) {
                    ndp[nj] = ndp[nj] == -1 ? dp[j + MAX] : std::min(ndp[nj], dp[j + MAX]);
                }
            }

            for(int j = -MAX; j <= MAX; j++) {
                int nj = j + MAX + b[i];
                if(nj <= MAX * 2 && dp[j + MAX] != -1) {
                    ndp[nj] = ndp[nj] == -1 ? dp[j + MAX] + a[i] : std::min(ndp[nj], dp[j + MAX] + a[i]);
                }
            }
        }

        std::swap(dp, ndp);
    }

    int64_t ans = INF;
    for(int i = MAX + 1; i <= MAX * 2; i++) {
        if(dp[i] != -1) {
            ans = std::min(ans, dp[i]); 
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
