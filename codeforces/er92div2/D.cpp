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

    int L, R, X, Y;
    std::cin >> L >> R >> X >> Y;
    
    if(L > X) {
        std::swap(L, X);
        std::swap(R, Y);
    }

    int64_t ans = 0;
    if(R >= X) {
        int free = std::min(R, Y) - std::max(L, X);
        int extend = X - L + std::abs(R - Y);
        K = std::max(int64_t(0), K - int64_t(free) * N);

        int p = 0;
        while(p < N && K) {
            if(K >= extend) {
                K -= extend;
                ans += extend;
                p += 1;
            } else {
                ans += K;
                K = 0;
                break;
            }
        }
        ans += K * 2;
    } else {
        int gap = X - R;
        int extend = Y - L;
        int p = 0;
        ans = gap;
        
        if(K <= extend) {
            ans += K;
            K = 0;
        } else {
            K -= extend;
            ans += extend;
            p += 1;

            if(extend <= gap) {
                ans += K * 2;
                K = 0;
            } else {
                while(K > gap && p < N) {
                    int d = std::min(K, extend);
                    ans += gap + d;
                    K -= d;
                    p += 1;
                } 
                ans += K * 2;
                K = 0;
            }
        }
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
