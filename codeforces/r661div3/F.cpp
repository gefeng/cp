#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    std::vector<int> m;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
        m.push_back(A[i].first);
        m.push_back(A[i].second);
    }

    std::ranges::sort(m); 
    
    m.erase(std::unique(m.begin(), m.end()), m.end());
    int n = m.size();

    for(auto& [l, r] : A) {
        for(int i = 0; i < n; i++) {
            if(m[i] == l) {
                l = i;
                break;
            }
        }
        for(int i = 0; i < n; i++) {
            if(m[i] == r) {
                r = i;
                break;
            }
        }
    }

    std::ranges::sort(A.begin(), A.end());

    std::vector<std::vector<int>> a(n);
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0)); 
    for(auto [l, r] : A) {
        a[l].push_back(r);
    }

    for(int l = n - 1; l >= 0; l--) {
        for(int r = l; r < n; r++) {
            if(r > l) {
                dp[l][r] = std::max(dp[l][r], dp[l + 1][r]);
            }
            int size = a[l].size();
            bool covered = false;
            for(int i = 0; i < size; i++) {
                int x = a[l][i];
                if(x == r) {
                    covered = true;
                } else if(x < r) {
                    dp[l][r] = std::max(dp[l][r], dp[l][x] + dp[x + 1][r]);
                } 
            } 

            if(covered) {
                dp[l][r] += 1;
            }
        } 
    }

    std::cout << dp[0][n - 1] << '\n';
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
