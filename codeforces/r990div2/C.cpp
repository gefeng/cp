#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> A(2, std::vector<int>(N, 0));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> A[i][j];
        }
    }

    int64_t ans = -INF;
    for(int i = 0; i < N; i++) {
        int64_t sum = A[0][i] + A[1][i]; 
        std::vector<std::pair<int, int>> a;
        for(int j = 0; j < N; j++) {
            if(i != j) {
                a.emplace_back(A[0][j], A[1][j]);
            }
        }

        std::sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
                    return x.first - x.second > y.first - y.second;
                });

        for(auto [x, y] : a) {
            if(x - y >= 0) {
                sum += x;
            } else {
                sum += y;
            }
        }
        
        ans = std::max(ans, sum);
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
