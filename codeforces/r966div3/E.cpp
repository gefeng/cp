#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    int W;
    std::cin >> W;
    std::vector<int> A(W);
    for(int i = 0; i < W; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> a;
    std::vector<std::vector<int64_t>> b(N + 1, std::vector<int64_t>(M + 1, 0));
    for(int i = 0; i <= N - K; i++) {
        for(int j = 0; j <= M - K; j++) {
            b[i][j] += 1;
            b[i][j + K] -= 1;
            b[i + K][j] -= 1;
            b[i + K][j + K] += 1;
        }
    }

    std::vector<std::vector<int64_t>> g(N, std::vector<int64_t>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(i - 1 >= 0) {
                g[i][j] += g[i - 1][j];
            } 
            if(j - 1 >= 0) {
                g[i][j] += g[i][j - 1];
            }
            if(i - 1 >= 0 && j - 1 >= 0) {
                g[i][j] -= g[i - 1][j - 1];
            }
            g[i][j] += b[i][j];
            a.push_back(g[i][j]);
        }
    }

    std::sort(a.begin(), a.end(), std::greater<int64_t>());
    std::sort(A.begin(), A.end(), std::greater<int>());
    
    int64_t ans = 0;
    int m = a.size();
    for(int i = 0, j = 0; i < W && j < m; i++, j++) {
        ans += A[i] * a[j];
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
