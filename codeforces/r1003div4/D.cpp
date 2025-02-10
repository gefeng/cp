#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<std::pair<int64_t, int>> a(N);
    for(int i = 0; i < N; i++) {
        int64_t sum = 0;
        a[i].second = i;
        for(int j = 0; j < M; j++) {
            sum += A[i][j];
        }
        a[i].first = sum;
    }

    std::sort(a.begin(), a.end(), std::greater<std::pair<int64_t, int>>());

    int64_t cnt = N * M;
    int64_t ans = 0;
    for(auto [_, i] : a) {
        for(int j = 0; j < M; j++) {
            ans += A[i][j] * cnt;
            cnt--;
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
