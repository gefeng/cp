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

    std::string S;
    std::cin >> S;
    
    std::vector<std::vector<int64_t>> A(N, std::vector<int64_t>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j]; 
        }
    }

    std::vector<std::vector<int64_t>> psum_1(N, std::vector<int64_t>(M + 1, 0));
    std::vector<std::vector<int64_t>> psum_2(M, std::vector<int64_t>(N + 1, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            psum_1[i][j + 1] = psum_1[i][j] + A[i][j];
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            psum_2[i][j + 1] = psum_2[i][j] + A[j][i];
        }
    }

    A[0][0] = S[0] == 'D' ? -psum_1[0][M] : -psum_2[0][N];
    int64_t acc = A[0][0];
    int r = 0;
    int c = 0;
    int n = S.size();
    int64_t sum = 0;
    for(int i = 0; i < n; i++) {
        if(S[i] == 'D') {
            r += 1;
        } else {
            c += 1;
        }
        
        if(i + 1 < n && S[i] != S[i + 1]) {
            if(S[i] == 'R') {
                A[r][c] = sum - psum_1[r][M] - acc;  
            } else {
                A[r][c] = sum - psum_2[c][N] - acc;
            }
            acc = A[r][c];
        } else {
            if(S[i] == 'R') {
                A[r][c] = sum - psum_2[c][N];
                acc += A[r][c];
            } else {
                A[r][c] = sum - psum_1[r][M];
                acc += A[r][c];
            }
        }
    }

    auto check = [&]() {
        for(int i = 0; i < N; i++) {
            int64_t x = 0;
            for(int j = 0; j < M; j++) {
                x += A[i][j]; 
            }
            assert(x == sum);
        }
        for(int i = 0; i < M; i++) {
            int64_t x = 0;
            for(int j = 0; j < N; j++) {
                x += A[j][i]; 
            }
            assert(x == sum);
        }
    };
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cout << A[i][j] << " \n"[j == M - 1];
        }
    }

    check();
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
