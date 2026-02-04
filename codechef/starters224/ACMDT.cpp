#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = static_cast<int64_t>(1e9);

void run_case() {
    int64_t B, G, X, Y, N;
    std::cin >> B >> G >> X >> Y >> N;

    if(X > Y) {
        std::swap(B, G);
        std::swap(X, Y);
    }

    if(X + Y > N || B < X || G < Y) {
        std::cout << -1 << '\n';
        return;
    }

    int64_t lo = 0;
    int64_t hi = MAX;
    int64_t ans = -1;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        int64_t b = B - mid * X;
        int64_t g = G - mid * Y;
        int64_t space = N - X - Y;

        if(b < 0 || g < 0) {
            hi = mid - 1;
            continue;
        }
        
        if(space * mid < b + g) {
            lo = mid + 1;
        } else {
            ans = mid;
            hi = mid - 1;
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
