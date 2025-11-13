#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<int> A(K);
    for(int i = 0; i < K; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);
    
    auto solve = [&](int n, int m) {
        int save = 0;
        for(int i = K - 1; i >= 0; i--) {
            int c = A[i] / n;
            if(c < 2) {
                continue;
            }

            if(m == 1) {
                if(save) {
                    m = 0;
                } else {
                    break;
                }
            } else {
                m = std::max(0, m - c);
                if(c > 2) {
                    save = 1;
                }
            }
        }
        return m == 0;
    };

    std::cout << (solve(N, M) || solve(M, N) ? "Yes" : "No") << '\n';
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
