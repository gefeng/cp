#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < Q; i++) {
        int64_t K;
        std::cin >> K;

        int64_t res = 0;
        std::vector<int64_t> a(A);
        for(int b = 60; b >= 0; b--) {
            int64_t cost = 0;
            int64_t mask = (1LL << (b + 1)) - 1;
            for(int64_t x : a) {
                if((1LL << b) & x) {
                    continue;
                }
                cost += (1LL << b) - (mask & x);
                if(cost > K) {
                    break;
                }
            }

            if(cost <= K) {
                res |= 1LL << b;
                K -= cost;

                for(int j = 0; j < N; j++) {
                    if((1LL << b) & a[j]) {
                        continue;
                    }

                    a[j] ^= (mask & a[j]);
                    a[j] |= 1LL << b;
                }
            }
        }

        std::cout << res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
