#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N;
    std::cin >> N;

    int M;
    std::cin >> M;

    std::vector<int> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    int64_t sum = 0;
    int64_t ans = 0;
    for(int b = 0, i = 0; b <= 60; b++) {
        if(N & (int64_t(1) << b)) {
            int64_t v = int64_t(1) << b;

            while(i < M && A[i] <= v) {
                sum += A[i];
                i += 1;
            }

            if(sum >= v) {
                sum -= v;
                continue;
            }

            if(i < M) {
                int64_t x = A[i];
                while(x != v) {
                    x /= 2;
                    ans += 1;
                }
                sum += A[i] - v;
                i += 1;
            } else {
                std::cout << -1 << '\n';
                return;
            }
        }
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
