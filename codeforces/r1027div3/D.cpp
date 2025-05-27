#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    std::array<int, 2> min_x = {INF, INF};
    std::array<int, 2> min_y = {INF, INF};
    std::array<int, 2> max_x = {0, 0};
    std::array<int, 2> max_y = {0, 0};
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
        if(A[i].first > max_x[0]) {
            max_x[1] = max_x[0];
            max_x[0] = A[i].first;
        } else if(A[i].first > max_x[1]) {
            max_x[1] = A[i].first;
        }

        if(A[i].first < min_x[0]) {
            min_x[1] = min_x[0];
            min_x[0] = A[i].first;
        } else if(A[i].first < min_x[1]) {
            min_x[1] = A[i].first;
        }

        if(A[i].second > max_y[0]) {
            max_y[1] = max_y[0];
            max_y[0] = A[i].second;
        } else if(A[i].second > max_y[1]) {
            max_y[1] = A[i].second;
        }

        if(A[i].second < min_y[0]) {
            min_y[1] = min_y[0];
            min_y[0] = A[i].second;
        } else if(A[i].second < min_y[1]) {
            min_y[1] = A[i].second;
        }
    }

    if(N == 1) {
        std::cout << 1 << '\n';
        return;
    }

    int64_t ans = int64_t(max_x[0] - min_x[0] + 1) * (max_y[0] - min_y[0] + 1);
    for(auto [x, y] : A) {
        int rx = x == max_x[0] ? max_x[1] : max_x[0]; 
        int lx = x == min_x[0] ? min_x[1] : min_x[0];
        int ry = y == max_y[0] ? max_y[1] : max_y[0];
        int ly = y == min_y[0] ? min_y[1] : min_y[0];

        int64_t tot = int64_t(rx - lx + 1) * (ry - ly + 1);
        if(tot == N - 1) {
            ans = std::min(ans, int64_t(rx - lx + 2) * (ry - ly + 1));
            ans = std::min(ans, int64_t(rx - lx + 1) * (ry - ly + 2));
        } else {
            ans = std::min(ans, tot);
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
