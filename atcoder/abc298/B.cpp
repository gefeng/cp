#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> A(N, std::vector<int>(N, 0));
    std::vector<std::vector<int>> B(N, std::vector<int>(N, 0));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> A[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> B[i][j];
        }
    }

    auto rotate = [&]() {
        std::vector<std::vector<int>> m(N, std::vector<int>(N, 0)); 
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                m[i][j] = A[i][j];
            }
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                A[i][j] = m[N - 1 - j][i];
            }
        }
    };

    auto is_ok = [&]() {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(A[i][j] == 1 && B[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    };

    auto print = [&]() {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                std::cout << A[i][j] << ' ';
            }
            std::cout << '\n';
        }
    };

    for(int i = 0; i < 4; i++) {
        rotate();
        if(is_ok()) {
            std::cout << "Yes" << '\n'; 
            return;
        }
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
