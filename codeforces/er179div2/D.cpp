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
    
    std::vector<int> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end(), [](int x, int y) {
                return x / 100 < y / 100; 
            });

    std::vector<std::vector<int>> ans(N, std::vector<int>(6));
    for(int i = 0, j = 0; i < N; i += 2, j++) {
        for(int k = 0; k < 6; k += 2) {
            ans[i][k] = A[j];
            ans[i][k + 1] = A[M - 1 - j];
        }

        if(i + 1 < N) {
            for(int k = 0; k < 6; k += 2) {
                ans[i + 1][k] = A[M - 1 - j];
                ans[i + 1][k + 1] = A[j];
            } 
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 6; j++) {
            std::cout << ans[i][j] << " \n"[j == 5];
        }
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
