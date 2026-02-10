#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X, Y;
    std::cin >> N >> X >> Y;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = 0;
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i] - (A[i] / X * (X - Y) + (A[i] % X));
    }

    for(int i = 0; i < N; i++) {
        int64_t x = A[i] - (A[i] / X * (X - Y) + (A[i] % X));
        ans = std::max(ans, sum - x + A[i]);
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
