#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N, X;
    std::cin >> N >> X;

    int64_t ans = 0;
    
    int cnt = __builtin_popcount(X);

    if(cnt >= N) {
        ans = X; 
    } else {
        int d = N - cnt;
        ans = X; 
        //std::cout << d << ' ' << cnt << '\n';
        if(d % 2 == 0) {
            ans += d;
        } else {
            ans += d - 1;
            //std::cout << ans << '\n';
            // if(d == 1) {
            //     if(N == 1) {
            //         ans = -1;
            //     } else {
            //         for(int i = 0; i <= 30; i++) {
            //             if(X & (1 << i)) {
            //                 continue;
            //             }
            //             ans += 1 << (i + 1);
            //             break;
            //         }
            //     }
            // } else {
            //     
            //     // if(X % 2 == 0 && cnt) {
            //     //     ans += 2;
            //     // } else {
            //     //     ans += 4;
            //     // }
            // }

            int64_t sum = ans;
            ans = INF;
            if(d > 1) {
                ans = std::min(ans, sum + 4);
            }
                        
            if(cnt > 1) {
                ans = std::min(ans, sum + 2);
            }
            
            if(cnt == 1) {
                for(int i = 0; i <= 30; i++) {
                    if(X & (1 << i)) {
                        continue;
                    } 
                    ans = std::min(ans, sum + (int64_t(1) << (i + 1)));
                    break;
                }
            }

            ans = ans == INF ? -1 : ans;
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
