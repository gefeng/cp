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
            std::cin >> A[i][j];
            A[i][j] -= 1;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> B[i][j];
            B[i][j] -= 1;
        }
    }

    std::vector<int> row(N * M, 0);
    std::vector<int> col(N * M, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            row[A[i][j]] = i;
            col[A[i][j]] = j;
        }
    }

    for(int i = 0; i < N; i++) {
        int r = row[B[i][0]];
        for(int j = 1; j < M; j++) {
            if(row[B[i][j]] != r) {
                std::cout << "No" << '\n';
                return;
            } 
        }
    }

    for(int i = 0; i < M; i++) {
        int c = col[B[0][i]];
        for(int j = 1; j < N; j++) {
            if(col[B[j][i]] != c) {
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
