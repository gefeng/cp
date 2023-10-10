#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

constexpr double eps = 1e-8;

void run_case() {
    int PX, PY, AX, AY, BX, BY;
    std::cin >> PX >> PY >> AX >> AY >> BX >> BY;
    
    double ans = 0;

    auto dist = [](double x1, double y1, double x2, double y2) {
        return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    };
    
    double d1 = dist(0, 0, AX, AY);
    double d2 = dist(0, 0, BX, BY);
    double d3 = dist(PX, PY, AX, AY);
    double d4 = dist(PX, PY, BX, BY);
    double d5 = dist(AX, AY, BX, BY);

    if(d1 - d2 <= eps && d3 - d4 <= eps) {
        ans = std::max(d1, d3);
    } else if(d2 - d1 <= eps && d4 - d3 <= eps) {
        ans = std::max(d2, d4);
    } else {
        ans = std::max(std::min(d1, d2), std::min(d3, d4));
        if(ans * 2.0 - d5 <= eps) {
            ans = d5 / 2.0;
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
