#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    // 1 4
    // 3 2

    int N, Q;
    std::cin >> N >> Q;

    int64_t size = int64_t(pow(2, N));
    
    for(int i = 0; i < Q; i++) {
        std::string S;
        std::cin >> S;
        if(S == "->") {
            int64_t X, Y;
            std::cin >> X >> Y;
            X -= 1;
            Y -= 1;

            int64_t sr = 0;
            int64_t sc = 0;
            int64_t l = 1;
            int64_t r = size * size;
            int64_t len = size;
            while(l != r) {
                len /= 2;
                int64_t n = sr + len;
                int64_t m = sc + len;
                int64_t v = (r - l + 1) / 4;
                if(X < n) {
                    if(Y < m) {
                        // 1
                        r = l + v - 1;
                    } else {
                        // 4
                        l += v * 3;
                        sc += len;
                    }
                } else {
                    if(Y < m) {
                        // 3
                        sr += len;
                        r = l + v * 3 - 1;
                        l += v * 2;
                    } else {
                        // 2
                        sr += len;
                        sc += len;
                        r = l + v * 2 - 1;
                        l += v;
                    }
                }
            }
            std::cout << l << '\n';
        } else {
            int64_t D;
            std::cin >> D;

            int64_t sr = 0;
            int64_t sc = 0;
            int64_t l = 1;
            int64_t r = size * size;
            int64_t len = size;
            
            while(l != r) {
                int64_t v = (r - l + 1) / 4;
                len /= 2;
                // 1
                if(D >= l && D <= l + v - 1) {
                    r = l + v - 1;
                    continue;
                }

                // 4
                if(D >= l + v * 3 && D <= r) {
                    sc += len;
                    l += v * 3;
                    continue;
                }

                // 3
                if(D >= l + v * 2 && D <= l + v * 3 - 1) {
                    sr += len;
                    r = l + v * 3 - 1;
                    l += v * 2;
                    continue;
                }
                
                // 2
                sr += len;
                sc += len;
                r = l + v * 2 - 1;
                l += v;
            }

            std::cout << sr + 1 << ' ' << sc + 1 << '\n';
        }
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
