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
    
    std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
    std::vector<std::vector<int>> B(N, std::vector<int>(M, 0));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            char C;
            std::cin >> C;
            A[i][j] = C - '0';
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            char C;
            std::cin >> C;
            B[i][j] = C - '0';
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int k = 0;
            while(A[i][j] != B[i][j] && k < 3) {
                if(i + 1 < N && j + 1 < M) {
                    A[i][j] = (A[i][j] + 1) % 3;
                    A[i + 1][j + 1] = (A[i + 1][j + 1] + 1) % 3;
                    A[i][j + 1] = (A[i][j + 1] + 2) % 3;
                    A[i + 1][j] = (A[i + 1][j] + 2) % 3;
                    k += 1;
                } else {
                    break;
                }
            }

            if(A[i][j] != B[i][j]) {
                std::cout << "No" << '\n';
                return;
            }
        }
    }

    std::cout << "Yes" << '\n';
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
