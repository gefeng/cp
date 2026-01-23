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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> ans(N, std::vector<int>(N, 0));
    
    for(int i = 0; i < N; i++) {
        ans[i][i] = A[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            ans[i][j] = (ans[i][j - 1] + i) % N;
        }

        for(int j = i - 1; j >= 0; j--) {
            ans[i][j] = (ans[i][j + 1] - i + N) % N;
        }

        for(int j = 0; j < N; j++) {
            std::cout << ans[i][j] << " \n"[j == N - 1];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
