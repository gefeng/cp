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
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
    
    int parity = 0;
    int cnt_0 = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
            if(A[i][j] < 0) {
                parity ^= 1;
            }
            if(A[i][j] == 0) {
                cnt_0 += 1;
            }
        }
    }

    int ans = 0;
    if(parity == 0 || cnt_0) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                ans += std::abs(A[i][j]);
            }
        }
    } else {
        int min_v = INF;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                min_v = std::min(min_v, std::abs(A[i][j]));
                ans += std::abs(A[i][j]);
            }
        }

        ans -= 2 * abs(min_v);
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
