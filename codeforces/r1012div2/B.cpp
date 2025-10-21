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

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> is_prefix(N, std::vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(A[i][j] == '1') {
                is_prefix[i][j] = j == 0 || is_prefix[i][j - 1];
            }
        }
    }

    for(int i = 0; i < M; i++) {
        std::vector<int> is_good(N, 0);
        for(int j = 0; j < N; j++) {
            if(A[j][i] == '1') {
                is_good[j] = j == 0 || is_good[j - 1];
            }
        }
        for(int j = 0; j < N; j++) {
            if(is_good[j]) {
                is_prefix[j][i] = 1;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(A[i][j] == '1' && !is_prefix[i][j]) {
                std::cout << "NO" << '\n';
                return;
            }
        }
    }

    std::cout << "YES" << '\n';
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
