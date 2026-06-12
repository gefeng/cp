#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X, Y, Z;
    std::cin >> N >> X >> Y >> Z;

    int t = (N + X + Y - 1) / (X + Y);
    
    int tot = X * Z;
    if(tot >= N) {
        std::cout << std::min(t, (N + X - 1) / X) << '\n';
    } else {
        int extra = (N - tot + 10 * Y + X - 1) / (10 * Y + X);
        std::cout << std::min(t, Z + extra) << '\n';
    }
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
