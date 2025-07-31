#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>

constexpr double MAX = 1e15;
constexpr double EPS = 1e-9;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    double lo = 0.0;
    double hi = MAX;
    double ans = 0.0;

    for(int _ = 0; _ < 100; _++) {
        double mid = (lo + hi) / 2.0;
        
        std::vector<double> dp(N + 2, 0.0);
        
        double sum = 0;
        for(int i = N; i >= 1; i--) {
            dp[i] = std::min(dp[i + 1] + A[i - 1], mid / (N + 1) + B[i - 1]);
            sum += dp[i];
        }

        if(std::abs(mid - sum) <= EPS) {
            ans = dp[1];
            break;
        }

        if(sum < mid) {
            hi = mid;
        } else {
            lo = mid;
        }
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
