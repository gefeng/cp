#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, Y, R;
    std::cin >> N >> Y >> R;

    int ans = 0;
    int d = std::min(N, R);
    
    ans += d;
    N -= d;

    d = std::min(N, Y / 2);
    ans += d;

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
