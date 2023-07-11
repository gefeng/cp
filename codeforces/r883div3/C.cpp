#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, H;
    std::cin >> N >> M >> H;

    std::vector<std::vector<int>> A(N, std::vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }

        std::sort(A[i].begin(), A[i].end());
    }

    std::vector<std::vector<int64_t>> a(N, std::vector<int64_t>(3));
    for(int i = 0; i < N; i++) {
        int64_t score = 0;
        int64_t penalty = 0;
        int64_t t = 0;
        for(int j = 0; j < M; j++) {
            if(t + A[i][j] <= H) {
                score += 1;
                t += A[i][j];
                penalty += t;
            } else {
                break;
            }
        }

        a[i] = {score, penalty, i};
    }

    std::sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
                if(x[0] == y[0] && x[1] == y[1]) {
                    return x[2] < y[2]; 
                }
                if(x[0] == y[0]) {
                    return x[1] < y[1];
                }
                return x[0] > y[0];
            });

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(a[i][2] == 0) {
            ans = i + 1;
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
