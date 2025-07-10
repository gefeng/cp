#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N;
    std::cin >> N;

    std::array<int, 4> T = {};
    for(int i = 0; i < 4; i++) {
        std::cin >> T[i];
    }

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t sum = std::accumulate(A.begin(), A.end(), int64_t(0));
    int64_t c = int64_t(T[2] - T[0]) * (T[2] - T[0]) + int64_t(T[3] - T[1]) * (T[3] - T[1]);

    if(c == 0) {
        if(N == 1) {
            std::cout << "No" << '\n';
            return;
        }
        if(N == 2) {
            std::cout << (A[0] == A[1] ? "Yes" : "No") << '\n';
            return;
        }

        for(int i = 0; i < N; i++) {
            if(A[i] > sum - A[i]) {
                std::cout << "No" << '\n';
                return;
            }
        }

        std::cout << "Yes" << '\n';
    } else {
        if(N == 1) {
            std::cout << (sum * sum == c ? "Yes" : "No") << '\n';
            return;
        }

        if(sum * sum < c) {
            std::cout << "No" << '\n';
            return;
        }
        
        for(int i = 0; i < N; i++) {
            int64_t x = 2 * A[i] - sum;
            if(x <= 0) {
                continue;
            }
            if(c < x * x) {
                std::cout << "No" << '\n';
                return;
            }
        }
        std::cout << "Yes" << '\n';
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
