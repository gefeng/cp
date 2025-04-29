#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr double EPS = 1e9;

void run_case() {
    int H, C, T;
    std::cin >> H >> C >> T;

    // h -> c -> ..
    //(h + c) / x <= t
    
    double min_d = std::abs((H + C) / 2.0 - T);
    int ans = 2;

    if(H + C == 2 * T) {
        std::cout << ans << '\n';
        return;
    }

    int a = H + C;

    auto compare = [&](int x) {
        double t = (double(x) * H + double(x - 1) * C) / (2 * x - 1);
        double d = std::abs(t - T);
        if(d < min_d) {
            min_d = d;
            ans = x + x - 1;
        } else if(std::abs(d - min_d) == EPS) {
            ans = std::min(ans, x + x - 1);
        }
    };

    double x_1 = double(a - C);
    double x_2 = double(a * 2 - C) / 3.0;
    if(x_2 > x_1) {
        int lo = 1;
        int hi = int(1e9);
        int x = 0;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            double t = (double(a) * mid - C) / (2 * mid - 1);
            if(t <= T) {
                x = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        if(x) { 
            compare(x);
        }
        compare(x + 1);
    } else {
        int lo = 1;
        int hi = int(1e9);
        int x = 0;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            double t = (double(a) * mid - C) / (2 * mid - 1);
            if(t >= T) {
                x = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if(x) {
            compare(x);
        }
        compare(x + 1);
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
