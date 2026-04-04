#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(676767677);

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(N == 1) {
        std::cout << 1 << '\n';
        return;
    }

    std::vector<std::vector<int>> a(M);
    for(int i = 0; i < N; i++) {
        a[A[i]].push_back(i);
    }

    int64_t ans = 1;
    int64_t pre_sat = 0;
    int64_t sat = 0;
    std::vector<int> solved(N, 0);
    for(int i = 0; i < M; i++) {
        if(i == 0) {
            for(int p : a[i]) {
                solved[p] = 1;
                sat++;
            }
            continue;
        }

        for(int p : a[i]) {
            if(p == 0) {
                if(!solved[p + 1]) {
                    std::cout << 0 << '\n';
                    return;
                }
                if(A[p + 1] == A[p] - 1) {
                    ans *= sat;
                    ans %= MOD;
                } else {
                    ans *= sat - pre_sat;
                    ans %= MOD;
                }
            } else if(p == N - 1) {
                if(!solved[p - 1]) {
                    std::cout << 0 << '\n';
                    return;
                }
                if(A[p - 1] == A[p] - 1) {
                    ans *= sat;
                    ans %= MOD;
                } else {
                    ans *= sat - pre_sat;
                    ans %= MOD;
                }
            } else {
                if(!solved[p + 1] && !solved[p - 1]) {
                    std::cout << 0 << '\n';
                    return;
                }

                if((solved[p + 1] && A[p + 1] != A[p] - 1) || (solved[p - 1] && A[p - 1] != A[p] - 1)) {
                    ans *= sat - pre_sat;
                    ans %= MOD;
                } else {
                    ans *= sat;
                    ans %= MOD;
                }
            }
        }

        pre_sat = sat;
        for(int p : a[i]) {
            solved[p] = 1;
            sat++;
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
