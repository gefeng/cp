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
    std::vector<std::vector<int>> psum(M, std::vector<int>(N + 1, 0));
    int ones = 0; 
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
            ones += A[i][j];
        }
    }

    for(int c = 0; c < M; c++) {
        for(int r = 0; r < N; r++) {
            psum[c][r + 1] = psum[c][r] + A[r][c];
        }
    }

    int t = ones / 2;
    int64_t max_v = static_cast<int64_t>(t) * ((ones + 1) / 2);
    std::string path = "";
    
    int r = 0;
    int c = 0;
    while(c < M) {
        if(r == N) {
            path.push_back('R');
            c += 1;
            continue;
        }

        int cnt = psum[c][N] - psum[c][r];
        if(cnt <= t) {
            path.push_back('R');
            t -= cnt;
            c += 1;
            continue;
        }

        while(cnt > t) {
            path.push_back('D');
            r += 1; 
            cnt = psum[c][N] - psum[c][r];
        }
        
        t -= cnt;
        c += 1;
        path.push_back('R');
    }

    while(r < N) {
        path.push_back('D');
        r += 1;
    }

    std::cout << max_v << '\n' << path << '\n';
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
