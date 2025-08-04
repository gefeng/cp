#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(A[i][j] == -1) {
                continue;
            }
            std::vector<int> a;
            a.push_back(A[i][j]);
            A[i][j] = -1;
            if(M - 1 - j != j) {
                a.push_back(A[i][M - 1 - j]);
                A[i][M - 1 - j] = -1;
            }
            if(N - 1 - i != i) {
                a.push_back(A[N - 1 - i][j]);
                A[N - 1 - i][j] = -1;
            }
            if(M - 1 - j != j && N - 1 - i != i) {
                a.push_back(A[N - 1 - i][M - 1 - j]);
                A[N - 1 - i][M - 1 - j] = -1;
            }

            int size = a.size();
            int64_t min_v = INF;
            for(int i = 0; i < size; i++) {
                int64_t cnt = 0;
                for(int j = 0; j < size; j++) {
                    cnt += std::abs(a[i] - a[j]);
                }
                min_v = std::min(min_v, cnt);
            }
            ans += min_v;
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
