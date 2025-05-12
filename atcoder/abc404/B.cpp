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

    std::vector<std::string> A(N);
    std::vector<std::string> B(N);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    auto rotate = [&]() {
        std::vector<std::string> a(A);
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                a[j][N - 1 - i] = A[i][j];
            }
        }

        A = std::move(a);
    };

    int ans = N * N;
    for(int i = 0; i < 4; i++) {
        int cnt = 0;
        for(int r = 0; r < N; r++) {
            for(int c = 0; c < N; c++) {
                if(A[r][c] != B[r][c]) {
                    cnt += 1;
                }
            }
        }
        ans = std::min(ans, cnt + i);

        rotate();
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
