#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K, R, C;
    std::cin >> N >> K >> R >> C;
    R -= 1;
    C -= 1;

    std::vector<std::string> ans(N, std::string(N, '.'));

    for(int i = 0; i < N / K; i++) {
        for(int j = 0; j < N / K; j++) {
            for(int k = 0; k < K; k++) {
                ans[i * K + k][j * K + k] = 'X';
            }
        }
    }
    
    if(ans[R][C] == '.') {
        int d = 0;
        for(int i = C; i < N; i++) {
            if(ans[R][i] == 'X') {
                d = i - C;
                break;
            }
        }
        if(d == 0) {
            for(int i = C; i >= 0; i--) {
                if(ans[R][i] == 'X') {
                    d = i - C;
                    break;
                }
            }
        }

        std::vector<std::string> tmp(ans);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                ans[i][j] = tmp[i][(j + d + N) % N];
            }
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << '\n';
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
