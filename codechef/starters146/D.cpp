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
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> A(N, std::vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    } 

    int64_t ans = INF;
    int64_t max_sum = 0;
    std::vector<std::pair<int64_t, int>> a(N);
    for(int i = 0; i < N; i++) {
        int64_t sum = 0;
        for(int x : A[i]) {
            sum += x;
        }
        
        int64_t l = 0;
        int64_t best = INF;
        for(int j = 0; j < M; j++) {
            int64_t d = std::max(l, sum - l - A[i][j]) + A[i][j];     
            best = std::min(best, d);
            l += A[i][j];
        }
        a[i] = {best, i};

        max_sum = std::max(max_sum, sum);
    }

    std::sort(a.begin(), a.end());

    if(N == 2) {
        ans = std::max(max_sum, a[0].first + a[1].first);
    } else {
        for(int i = 0; i < N; i++) {
            auto [x, j] = a[i];

            int64_t sum = 0;
            for(int k = 0; k < M; k++) {
                sum += A[j][k];
            }

            int64_t l = 0;
            for(int k = 0; k < M; k++) {
                int64_t d1 = 0;
                int64_t d2 = 0;
                if(i < N - 2) {
                    d1 = a[N - 2].first + a[N - 1].first + A[j][k];
                } else if(i == N - 2) {
                    d1 = a[N - 1].first + a[N - 3].first + A[j][k];
                } else if(i == N - 1) {
                    d1 = a[N - 2].first + a[N - 3].first + A[j][k];
                }
                
                d2 = std::max(l, sum - l - A[j][k]) + A[j][k];
                if(i != N - 1) {
                    d2 += a[N - 1].first;
                } else {
                    d2 += a[N - 2].first;
                }

                ans = std::min(ans, std::max(max_sum, std::max(d1, d2)));

                l += A[j][k];
            }
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
