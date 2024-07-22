#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t X, Y, K;
    std::cin >> X >> Y >> K;
    
    int64_t x = X;
    while(K) {
        if(x == 1) {
            x += K % (Y - 1);
            if(x % Y == 0) {
                x = 1;
            }
            break;
        }
        if(x < Y) {
            int64_t d = std::min(Y - x, K);
            x += d;
            K -= d;
            while(x % Y == 0) {
                x /= Y;
            }
        } else {
            int64_t c = (x + 1 + Y - 1) / Y;
            int64_t d = std::min(Y * c - x, K);
            x += d;
            K -= d;
            while(x % Y == 0) {
                x /= Y;
            }
        }
    }

    std::cout << x << '\n';
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
