#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, B, X;
    std::cin >> N >> B >> X;

    std::vector<int> A(N);
    int max_k = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        max_k = std::max(max_k, A[i]);
    }

    std::vector<int64_t> strength(max_k + 1, 0);
    std::vector<int64_t> extra(max_k + 2, 0);
    
    for(int i = 0; i < N; i++) {
        for(int k = 1; k <= A[i]; k++) {
            int64_t s = 0;
            if(A[i] % k == 0) {
                int64_t x = A[i] / k;
                s = ((int64_t)k * (k - 1) / 2) * x * x;
            } else {
                int64_t x = A[i] / k;
                int64_t y = A[i] / k + 1;
                int64_t a = A[i] % k;
                int64_t b = k - a;
                s = a * (a - 1) / 2 * y * y + b * (b - 1) / 2 * x * x + a * b * x * y;
            }

            s *= B;
            strength[k] += s;
            if(k == A[i] && A[i] < max_k) {
                extra[A[i] + 1] += s;
                extra[max_k + 1] -= s;
            }
        } 
    }

    int64_t rolling = 0;
    int64_t ans = 0;
    for(int i = 1; i <= max_k; i++) {
        rolling += extra[i];
        ans = std::max(ans, rolling + strength[i] - (int64_t)(i - 1) * X);
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
