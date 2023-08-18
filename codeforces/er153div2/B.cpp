#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int M, K, X, Y;
    std::cin >> M >> K >> X >> Y;

    int cnt = M / K;
    int rem = M % K;
    
    int ans = std::max(0, rem - X);
    
    ans += std::max(0, cnt - Y - std::max(0, (X - rem) / K));

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
