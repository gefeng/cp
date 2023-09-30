#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N, X, K;
    std::cin >> N >> X >> K;
    
    int64_t ans = 0;
    int64_t n = -1;
    for(int64_t p = 1; p <= N; p *= 2) {
        n += 1;
    }

    int64_t m = -1;
    for(int64_t p = 1; p <= X; p *= 2) {
        m += 1;
    }

    int64_t cur = X;
    int64_t pre = X;
    for(int64_t up = 0; up <= n && cur && K - up >= 0 && m >= 0; up++) {
        int64_t d = K - up;
        if(up) {
            if(d == 0) {
                ans += 1;
            } else {
                d -= 1;
                int64_t x = (pre % 2 == 0) ? pre + 1 : pre - 1;
                if(m + 1 + d <= n) {
                    int64_t p2 = (int64_t)pow((int64_t)2, d);
                    int64_t min_v = p2 * x;
                    int64_t max_v = p2 * (x + 1) - 1;
                    ans += min_v > N ? 0 : std::min(N, max_v) - min_v + 1;
                }
            }
        } else {
            if(d == 0) {
                ans += 1;
            } else {
                if(m + d <= n) {
                    int64_t p2 = (int64_t)pow((int64_t)2, d);
                    int64_t min_v = p2 * cur;
                    int64_t max_v = p2 * (cur + 1) - 1;
                    ans += min_v > N ? 0 : std::min(N, max_v) - min_v + 1;
                }
            }
        }
        pre = cur;
        cur /= 2;
        m -= 1;
    }    

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
