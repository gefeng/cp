#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    if(N == 1) {
        std::cout << 0 << '\n';
        return;
    }

    int d = 0;
    int now = 1;
    while(now * 2 <= N) {
        now *= 2;
        d += 1;
    }

    int ans = N;
    for(int i = 0, j = 1; i < d; i++, j <<= 1) {
        if(i >= K) {
            break;
        }
        int r = K - i;
        if(r >= i + 1) {
            ans -= j * 2 - j;
        } else {
            __int128_t x = i;
            __int128_t y = 1;
            __int128_t cnt = 0;
            for(int b = 0; b <= std::min(r - 1, i); b++) {
                if(b == 0) {
                    cnt += 1;
                } else {
                    cnt += x / y;
                    x *= (i - b);
                    y *= b + 1;
                }
            }
            ans -= cnt;
        }
    }

    if(d + 1 <= K) {
        ans -= 1;
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
