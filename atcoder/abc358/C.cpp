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

    int ans = N;
    for(int mask = 1; mask < (1 << N); mask++) {
        int have = 0;
        for(int i = 0; i < N; i++) {
            if(mask & (1 << i)) {
                for(int j = 0; j < M; j++) {
                    if(A[i][j] == 'o') {
                        have |= 1 << j;
                    }
                }
            }
        }

        if(have == (1 << M) - 1) {
            ans = std::min(ans, __builtin_popcount(mask));
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
