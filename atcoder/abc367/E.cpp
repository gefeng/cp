#include <iostream>
#include <utility>
#include <cassert> 
#include <algorithm> 
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int MAX = 60;

void run_case() {
    int N;
    int64_t K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    std::vector<int> B(N);

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
        B[i] -= 1;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> ans(N, 0);
    std::vector<std::vector<int>> jump(MAX + 1, std::vector<int>(N, 0));

    for(int i = 0; i < N; i++) {
        jump[0][i] = B[i];
    }

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < N; j++) {
            jump[i + 1][j] = jump[i][jump[i][j]];
        }
    }

    for(int i = 0; i < N; i++) {
        int p = i;
        for(int j = 0; j <= MAX; j++) {
            if(K & (int64_t(1) << j)) {
                p = jump[j][p]; 
            }
        }
        ans[i] = A[p];
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
