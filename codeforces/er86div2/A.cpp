#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t X, Y, A, B;
    std::cin >> X >> Y >> A >> B;

    int64_t ans = 0;
    
    if(A * 2 <= B) {
        std::cout << (X + Y) * A << '\n';
        return;
    }

    int64_t d = std::min(X, Y);
    ans = d * B;
    X -= d;
    Y -= d;
    ans += (X + Y) * A;

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
