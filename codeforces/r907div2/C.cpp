#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    int64_t ans = 0;
    int64_t x = 0;
    for(int l = 0, r = N - 1; l <= r; ) {
        if(l == r) {
            int64_t d = (A[l] - x) / 2;
            x += d;

            if(x <= 1) {
                ans += A[l];
            } else {
                ans += d + 1;
                ans += A[l] - d - x;
            }

            l += 1;
        } else {
            if(x + A[l] < A[r]) {
                x += A[l];
                ans += A[l];
                l += 1;
            } else {
                int64_t d = std::max((int64_t)0, A[r] - x);
                A[l] -= d;
                ans += d + 1;
                r -= 1;
                if(A[l] == 0) {
                    l += 1;
                }
                x = 0;
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
