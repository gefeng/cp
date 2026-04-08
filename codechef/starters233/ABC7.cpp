#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <numeric>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::array<int, 3>> A(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            std::cin >> A[i][j];
        }
        std::ranges::sort(A[i], std::greater<int>());
    }
    
    auto cmp = [&](const auto& x, const auto& y) {
        return A[x.first][x.second] < A[y.first][y.second];
    };

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);
    int min_v = INF;
    for(int i = 0; i < N; i++) {
        pq.emplace(i, 0);
        min_v = std::min(min_v, A[i][0]);
    }

    int ans = INF;
    while(true) {
        auto [i, j] = pq.top();
        ans = std::min(ans, A[i][j] - min_v);
        
        bool end = false;
        while(true) {
            auto [x, y] = pq.top();
            if(A[x][y] == A[i][j]) {
                if(y + 1 < 3) {
                    pq.pop();
                    pq.emplace(x, y + 1);
                    min_v = std::min(min_v, A[x][y + 1]);
                } else {
                    end = true;
                    break;
                }
            } else {
                break;
            }
        }

        if(end) {
            break;
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
