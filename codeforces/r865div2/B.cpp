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

    std::vector<std::vector<int>> ans(2, std::vector<int>(N));
    for(int i = 0, j = 2 * N ; i < N; i += 2, j -= 2) {
        ans[0][i] = j;
    }

    for(int i = 1, j = 2; i < N; i += 2, j += 2) {
        ans[0][i] = j;
    }

    for(int i = 0, j = 1; i < N; i += 2, j += 2) {
        ans[1][i] = j;
    }

    for(int i = N - 1, j = 2 * N - 1; i >= 0; i -= 2, j -= 2) {
        ans[1][i] = j;
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < N; j++) {
            std::cout << ans[i][j] << " \n"[j == N - 1];
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
