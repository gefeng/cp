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

    std::vector<std::vector<int>> ans(N, std::vector<int>(N, 0));
    
    for(int i = 0; i < N; i++) {
        ans[N / 2][i] = N - i; 
    }

    for(int i = N / 2 - 1; i >= 0; i--) {
        for(int j = 0; j < N; j++) {
            ans[i][j] = ans[i + 1][(j - 1 + N) % N];
        }
    }

    for(int i = N / 2 + 1; i < N; i++) {
        for(int j = 0; j < N; j++) {
            ans[i][j] = ans[i - 1][(j + 1) % N];
        }
    }

    for(int i = 0; i < N; i++) {
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
