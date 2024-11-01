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
    
    std::vector<std::vector<int>> A(N, std::vector<int>(5, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 5; j++) {
            std::cin >> A[i][j];
        }
    }

    for(int x = 0; x < 5; x++) {
        for(int y = x + 1; y < 5; y++) {
            int a = 0;
            int b = 0;
            int c = 0;
            for(int i = 0; i < N; i++) {
                if(A[i][x] && A[i][y]) {
                    c += 1;
                } else if(A[i][x]) {
                    a += 1;
                } else if(A[i][y]) {
                    b += 1;
                }
            }

            int d = std::min(c, std::max(0, N / 2 - a));
            a += d;
            c -= d;

            d = std::min(c, std::max(0, N / 2 - b));
            b += d;
            c -= d;
            
            if(a >= N / 2 && b >= N / 2) {
                std::cout << "YES" << '\n';
                return;
            }
        }
    }

    std::cout << "NO" << '\n';
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
