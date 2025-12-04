#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X;
    std::cin >> N >> X;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto overlap = [](int l1, int r1, int l2, int r2) {
        if(l1 > l2) {
            std::swap(l1, l2);
            std::swap(r1, r2);
        }
        return l2 <= r1;
    };

    int l = -1;
    int r = -1;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(l == -1) {
            l = A[i] - X;
            r = A[i] + X;
        } else {
            if(overlap(l, r, A[i] - X, A[i] + X)) {
                l = std::max(l, A[i] - X);
                r = std::min(r, A[i] + X);
            } else {
                l = A[i] - X;
                r = A[i] + X;
                ans += 1;
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
