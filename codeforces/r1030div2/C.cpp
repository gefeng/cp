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
    int64_t K;
    std::cin >> N >> K;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> target(60, 0);
    for(int i = 0; i < 60; i++) {
        target[i] = (int64_t(1) << (i + 1)) - 1;
    }

    int64_t ans = 0;
    for(int i = 0; i < 60; i++) {
        int64_t t = target[i];
        std::sort(A.begin(), A.end(), [&](int64_t x, int64_t y) {
                    x &= t;
                    y &= t;
                    return t - x < t - y;
                });
        for(int j = 0; j < N; j++) {
            int64_t x = A[j];
            x &= t;
            int64_t d = t - x;
            if(K >= d) {
                K -= d;
                A[j] = ((A[j] >> (i + 1)) << (i + 1)) | t;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        ans += __builtin_popcountll(A[i]);
    }

    std::cout << ans << '\n';
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
