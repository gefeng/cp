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

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> A[i].second;
    }

    int64_t ans = 0;
    int64_t d_1 = 0;
    int64_t d_2 = INF;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(A[i].second > A[i].first) {
            cnt += 1;
            d_1 = A[i].second - A[i].first;
        } else {
            d_2 = std::min(d_2, int64_t(A[i].first - A[i].second));
        }
    }

    if(cnt == 1) {
        for(int i = 0; i < N; i++) {
            ans += A[i].second;
        }
        if(d_1 > d_2) {
            ans -= d_1 - d_2;
        }
    } else {
        for(int i = 0; i < N; i++) {
            ans += std::min(A[i].first, A[i].second);
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
