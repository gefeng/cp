#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K, P;
    std::cin >> N >> K >> P;

    int ans = std::abs(K) / P + (std::abs(K) % P ? 1 : 0);
    
    if(ans > N) {
        std::cout << -1 << '\n';
        return;
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
