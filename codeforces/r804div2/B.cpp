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

    for(int i = 0, t = 0; i < N; i += 2, t ^= 1) {
        for(int j = 0, k = t; j < M; j+= 2, k ^= 1) {
            ans[i][j] = k;
            ans[i][j + 1] = k ^ 1;
        } 
        
        for(int j = 0, k = t ^ 1; j < M; j += 2, k ^= 1) {
            ans[i + 1][j] = k;
            ans[i + 1][j + 1] = k ^ 1;
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
