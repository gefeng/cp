#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t A, B, R;
    std::cin >> A >> B >> R;
 
    if(A > B) {
        std::swap(A, B);
    }
 
    int p = -1;
    for(int i = 63; i >= 0; i--) {
        if((A & (1LL << i)) != (B & (1LL << i))) {
            p = i;
            break;
        }
    }
 
    if(p == -1) {
        std::cout << 0 << '\n';
        return;
    }
 
    int64_t a = A;
    int64_t b = B;
    int64_t x = 0;
    int64_t ans = std::abs(A - B);
    for(int i = p - 1; i >= 0; i--) {
        int b1 = A & (1LL << i) ? 1 : 0;
        int b2 = B & (1LL << i) ? 1 : 0;
        if(b1 == 0 && b2 == 1) {
            if((x | (1LL << i)) <= R) {
                a ^= (1LL << i);
                b ^= (1LL << i);
                ans = std::min(ans, std::abs(a - b));
                x |= 1LL << i;
            }
        }
    }
 
    x = 0;
    if((x | (1LL << p)) <= R) {
        a = A ^ (1LL << p);
        b = B ^ (1LL << p);
        x = 1LL << p;
        ans = std::min(ans, std::abs(A - B));
        for(int i = p - 1; i >= 0; i--) {
            int b1 = A & (1LL << i) ? 1 : 0;
            int b2 = B & (1LL << i) ? 1 : 0;
            if(b1 == 1 && b2 == 0) {
                if((x | (1LL << i)) <= R) {
                    a ^= (1LL << i);
                    b ^= (1LL << i);
                    ans = std::min(ans, std::abs(a - b));
                    x |= 1LL << i;
                }
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
