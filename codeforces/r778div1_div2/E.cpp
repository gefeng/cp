#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int MAX = int(1e5);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(N == 1) {
        std::cout << 0 << '\n';
        return;
    }

    int max_v = *std::max_element(A.begin(), A.end());
    int m = std::sqrt(MAX);

    std::vector<std::map<int, int>> dp(N);
    std::vector<int> a(N); 

    auto solve = [&]() {
        int res = N - 2;

        for(int d = -m; d <= m; d++) {
            for(int i = 0; i < N; i++) {
                int c = A[i] - i * d;
                a[i] = c;
            }

            std::sort(a.begin(), a.end());
            
            for(int i = 0; i < N; ) {
                int j = i;
                while(i < N && a[i] == a[j]) {
                    i += 1;
                }
                res = std::min(res, N - (i - j));
            }
        }

        for(int i = 0; i < N; i++) {
            dp[i].clear();
        }

        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j <= std::min(N - 1, i + m); j++) {
                if((A[j] - A[i]) % (j - i) == 0) {
                    int d = (A[j] - A[i]) / (j - i);
                    if(std::abs(d) >= m) {
                        dp[j][d] = std::max(dp[j][d], dp[i][d] + 1);
                        res = std::min(res, N - dp[j][d] - 1);
                    }
                }
            }
        }

        return res;
    }; 

    int ans = solve();
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
