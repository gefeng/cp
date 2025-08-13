#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t A, B, X, Y, N;
    std::cin >> A >> B >> X >> Y >> N;

    int64_t da = A - X;
    int64_t db = B - Y;
    int64_t ans = 0;
    
    int64_t x = std::min(da, N);
    int64_t y = std::min(db, N - x);
    ans = (A - x) * (B - y);

    x = std::min(db, N);
    y = std::min(da, N - x);

    ans = std::min(ans, (A - y) * (B - x));

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
