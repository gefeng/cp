#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

constexpr double EPS = 1e-9;

void run_case(int T) {
    int N, P;
    std::cin >> N >> P;
    
    double p = P / 100.0;

    double lo = P;
    double hi = 100.0;
    double ans = 0.0;

    //(p / q) ^ N = p
    
    while(std::abs(hi - lo) > EPS) {
        double mid = (lo + hi) / 2.0;
    
        double x = std::pow(P / mid, N);

        if(x - p > -EPS) {
            ans = mid;
            lo = mid;
        } else {
            hi = mid;
        }
    }

    std::cout << std::fixed << std::setprecision(14);
    std::cout << "Case #" << T << ": " << ans - P << '\n';
}

int main() {
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
