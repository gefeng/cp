#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;
constexpr int MAX = (int)1e5;

void run_case() {
    int A, B;
    std::cin >> A >> B;

    int ans = INF;
    for(int i = 0; i <= MAX; i++) {
        ans = std::min(ans, (A + i) / (i + 1) + (B + i) / (i + 1) + i);
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
