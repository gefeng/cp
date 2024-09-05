#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X, Y, K;
    std::cin >> X >> Y >> K;

    int x = (X + K - 1) / K;
    int y = (Y + K - 1) / K;
    int ans = std::max(x, y) * 2;
    if(y < x) {
        ans -= 1;
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
