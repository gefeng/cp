#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<std::vector<int>> A(N, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<std::vector<int64_t>> psum_1(N + 1, std::vector<int64_t>(N + 1, 0));
    std::vector<std::vector<int64_t>> psum_2(N + 1, std::vector<int64_t>(N + 1, 0));
    std::vector<std::vector<int64_t>> psum_3(N + 1, std::vector<int64_t>(N + 1, 0));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            psum_1[i + 1][j + 1] = psum_1[i + 1][j] + psum_1[i][j + 1] - psum_1[i][j] + A[i][j];
            psum_2[i + 1][j + 1] = psum_2[i + 1][j] + psum_2[i][j + 1] - psum_2[i][j] + int64_t(A[i][j]) * i;
            psum_3[j + 1][i + 1] = psum_3[j + 1][i] + psum_3[j][i + 1] - psum_3[j][i] + int64_t(A[j][i]) * i;
        }
    }

    for(int i = 0; i < Q; i++) {
        int X1, Y1, X2, Y2;
        std::cin >> X1 >> Y1 >> X2 >> Y2;
        X1 -= 1;
        Y1 -= 1;
        X2 -= 1;
        Y2 -= 1;
        
        int w = Y2 - Y1 + 1;
        int64_t a = psum_1[X2 + 1][Y2 + 1] - psum_1[X1][Y2 + 1] - psum_1[X2 + 1][Y1] + psum_1[X1][Y1];
        int64_t b = psum_2[X2 + 1][Y2 + 1] - psum_2[X1][Y2 + 1] - psum_2[X2 + 1][Y1] + psum_2[X1][Y1];
        int64_t c = psum_3[X2 + 1][Y2 + 1] - psum_3[X1][Y2 + 1] - psum_3[X2 + 1][Y1] + psum_3[X1][Y1];
        b = (b - a * X1) * w;
        c = (c - a * Y1);
        std::cout << a + b + c << " \n"[i == Q - 1];
    }
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
