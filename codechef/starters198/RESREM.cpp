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
    
    std::vector<int> A(N);
    std::vector<int> B(M);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }    

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::vector<std::vector<int>> psum(2, std::vector<int>(M + 1, 0));
    for(int j = 0; j < 2; j++) {
        for(int i = 0; i < M; i++) {
            psum[j][i + 1] = psum[j][i] + (B[i] == j ? 1 : 0);
        }
    }

    int del = 0;
    for(int i = 0; i < N; i++) {
        int l = i - del;
        int r = std::min(M - 1, i);
        if(l <= r && psum[A[i]][r + 1] - psum[A[i]][l]) {
            del += 1;
        }
    }

    std::cout << N - del << '\n';
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
