#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t X, Y;
    std::cin >> X >> Y;

    int64_t ans = 0;
    if(X == Y) {
        ans = X;
    } else if(X > Y) {
        ans = X + Y;
    } else {
        if(Y % X == 0) {
            ans = X;
        } else {
            int64_t c = 0;
            if(Y - 2 * X < X) {
                c = 1; 
            } else {
                c = (Y - 2 * X + X - 1) / X; 
            }
            ans = (Y >> 1) + (X >> 1) * c;
        }
    }

    assert(ans >= 1 && (ans % X == Y % ans));
    
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
