#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    int x = N - 1 + M - 1;
    if(K < x || (K - x) % 2 == 1) {
        std::cout << "No" << '\n';
        return;
    }

    std::cout << "Yes" << '\n';
    std::vector<std::vector<int>> ans1(N, std::vector<int>(M - 1, 0));
    std::vector<std::vector<int>> ans2(N - 1, std::vector<int>(M, 0));
    for(int i = 1; i < M - 1; i += 2) {
        ans1[0][i] = 1;
    }

    for(int i = 0, c = ans1[0][M - 2] == 0 ? 1 : 0; i < N - 1; i++, c ^= 1) {
        ans2[i][M - 1] = c; 
    } 

    ans1[1][M - 2] = ans1[0][M - 2];
    ans1[2][M - 2] = ans1[0][M - 2];

    ans2[0][M - 2] = ans2[0][M - 1];
    ans2[1][M - 2] = ans2[0][M - 2];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M - 1; j++) {
            std::cout << (ans1[i][j] == 0 ? 'B' : 'R') << " \n"[j == M - 2];
        }
    }

    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < M; j++) {
            std::cout << (ans2[i][j] == 0 ? 'B' : 'R') << " \n"[j == M - 1];
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
