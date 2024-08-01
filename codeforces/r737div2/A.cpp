#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

constexpr double INF = 1e15;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    int64_t sum = 0;
    for(int x : A) {
        sum += x;
    }

    double ans = -INF;
    int64_t l = 0;
    int64_t r = 0;
    for(int i = 0; i < N - 1; i++) {
        l += A[i];
        r = sum - l;
        ans = std::max(ans, double(l) / (i + 1) + double(r) / (N - i - 1));
    }

    std::cout << std::setprecision(20) << ans << '\n';
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
