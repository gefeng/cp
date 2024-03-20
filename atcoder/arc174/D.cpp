#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = (int64_t)2e18;

void run_case() {
    int64_t N;
    std::cin >> N;
    
    int64_t ans = 0;
    int64_t x = 90;
    int64_t d = 10;
    while(true) {
        if(x - d <= N) {
            ans += 1;
        }

        if(x + d - 1 <= N) {
            ans += d;
        } else {
            ans += std::max((int64_t)0, N - x + 1);
            break;
        }

        if(d <= MAX / 90 && x <= (MAX - 90 * d) / 100) {
            x = x * 100 + 90 * d;
            d *= 10;
        } else {
            break;
        }
    }

    x = 1;
    d = 1;
    while(true) {
        if(x + d - 1 <= N) {
            ans += d;
        } else {
            ans += std::max((int64_t)0, N - x + 1);
            break;
        }

        if(x <= MAX / 100) {
            x *= 100;
            d *= 10;
        } else {
            break;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    //gen();
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
