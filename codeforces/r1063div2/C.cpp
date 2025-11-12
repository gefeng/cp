#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int INF = static_cast<int>(2e9);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> A(2, std::vector<int>(N, 0));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<int> suffix_min(N, INF);
    std::vector<int> suffix_max(N, 0);

    for(int i = N - 1; i >= 0; i--) {
        suffix_min[i] = i == N - 1 ? A[1][i] : std::min(suffix_min[i + 1], A[1][i]);
        suffix_max[i] = i == N - 1 ? A[1][i] : std::max(suffix_max[i + 1], A[1][i]);
    }

    int min_v = INF;
    int max_v = 0;
    std::vector<int> max_l(N * 2 + 1, -1);
    for(int c = 0; c < N; c++) {
        min_v = std::min(min_v, A[0][c]);
        max_v = std::max(max_v, A[0][c]);
        
        int r = std::max(max_v, suffix_max[c]);
        int l = std::min(min_v, suffix_min[c]);
        max_l[r] = std::max(max_l[r], l);
    }

    int64_t ans = 0;
    int l = -1;
    for(int r = 1; r <= N * 2; r++) {
        l = std::max(l, max_l[r]);
        if(l != -1) {
            ans += l;
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
