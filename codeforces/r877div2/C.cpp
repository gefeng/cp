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

    std::vector<std::vector<int>> ans(N, std::vector<int>(M, 0));

    int x = 1;
    for(int i = 1; i < N; i += 2) {
        for(int j = 0; j < M; j++) {
            ans[i][j] = x++;
        } 
    }

    for(int i = 0; i < N; i += 2) {
        for(int j = 0; j < M; j++) {
            ans[i][j] = x++;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cout << ans[i][j] << " \n"[j == M - 1];
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
