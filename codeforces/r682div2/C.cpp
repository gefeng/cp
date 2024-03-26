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
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    for(int i = 0, p = 0; i < N; i++, p ^= 1) {
        for(int j = 0; j < M; j++) {
            if(j % 2 == p) {
                if(A[i][j] % 2 == 1) {
                    A[i][j] += 1;
                } 
            } else {
                if(A[i][j] % 2 == 0) {
                    A[i][j] += 1;
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cout << A[i][j] << " \n"[j == M - 1];
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
