#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

void run_case() {
    int X, Y;
    std::cin >> X >> Y;

    int cnt = 0;
    for(int a = 1; a <= 6; a++) {
        for(int b = 1; b <= 6; b++) {
            if(a + b >= X || std::abs(a - b) >= Y) {
                cnt += 1;
            }
        }
    }

    double ans = double(cnt) / 36.0;
    
    std::cout << std::setprecision(20) << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
