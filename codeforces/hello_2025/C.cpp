#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int L, R;
    std::cin >> L >> R;
    
    if(R - L == 2) {
        std::cout << L << ' ' << L + 1 << ' ' << R << '\n';
        return;
    }

    int a = R;
    int b = 0;
    int c = 0;
    std::array<int, 3> ans = {};
    int64_t max_v = 0;
    
    int hb = -1;
    for(int i = 29; i >= 0; i--) {
        if((R & (1 << i)) && !(L & (1 << i))) {
            hb = i;
            break;
        }
    }

    a = R;
    b = L;
    for(int i = hb - 1; i >= 0; i--) {
        int b_1 = (R & (1 << i)) ? 1 : 0;
        int b_2 = (L & (1 << i)) ? 1 : 0;
        if(b_1 == b_2) {
            if(b_1 == 1) {
                a ^= 1 << i;
            } else {
                b ^= 1 << i;
            }
        }
    }

    c = a;
    for(int i = 0; i < 30; i++) {
        c ^= 1 << i;
        
        if(c >= L && c <= R) {
            int64_t s = int64_t(a ^ b) + (b ^ c) + (a ^ c);
            if(s > max_v) {
                max_v = s;
                ans = {a, b, c};
            }
        }
        
        c ^= 1 << i;
    }

    c = b;
    for(int i = 0; i < 30; i++) {
        c ^= 1 << i;
        
        if(c >= L && c <= R) {
            int64_t s = int64_t(a ^ b) + (b ^ c) + (a ^ c);
            if(s > max_v) {
                max_v = s;
                ans = {a, b, c};
            }
        }
        
        c ^= 1 << i;
    }

    std::cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
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
