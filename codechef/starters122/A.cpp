#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, X, Y, L;
    std::cin >> N >> M >> X >> Y >> L;

    X -= 1;
    Y -= 1;

    int l = Y / L;
    int r = (M - 1 - Y) / L;
    int u = X / L;
    int d = (N - 1 - X) / L; 
    
    int64_t ans = (int64_t)(l + r + 1) * (u + d + 1);
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
