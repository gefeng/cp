#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<std::vector<int>>> A(N, std::vector<std::vector<int>>(N, std::vector<int>(N, 0)));
    std::vector<std::vector<std::vector<int>>> psum(N + 1, std::vector<std::vector<int>>(N + 1, std::vector<int>(N + 1, 0)));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                std::cin >> A[i][j][k];
                psum[i + 1][j + 1][k + 1] = psum[i][j + 1][k + 1] + psum[i + 1][j][k + 1] + psum[i + 1][j + 1][k] - 
                    psum[i][j][k + 1] - psum[i][j + 1][k] - psum[i + 1][j][k] + psum[i][j][k] + A[i][j][k];
            }
        }
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int L1, R1, L2, R2, L3, R3;
        std::cin >> L1 >> R1 >> L2 >> R2 >> L3 >> R3;
        L1 -= 1;
        R1 -= 1;
        L2 -= 1;
        R2 -= 1;
        L3 -= 1;
        R3 -= 1;
        
        int sum = psum[R1 + 1][R2 + 1][R3 + 1] - psum[L1][R2 + 1][R3 + 1] - psum[R1 + 1][L2][R3 + 1] - psum[R1 + 1][R2 + 1][L3] + 
            psum[L1][L2][R3 + 1] + psum[L1][R2 + 1][L3] + psum[R1 + 1][L2][L3] - psum[L1][L2][L3];
    
        std::cout << sum << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
