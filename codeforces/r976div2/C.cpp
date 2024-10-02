#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t B, C, D;
    std::cin >> B >> C >> D;

    int64_t ans = 0;
    for(int i = 61; i >= 0; i--) {
        int bb = ((int64_t(1) << i) & B) ? 1 : 0;
        int bc = ((int64_t(1) << i) & C) ? 1 : 0;
        int bd = ((int64_t(1) << i) & D) ? 1 : 0;
        
        if(bd == 1) {
            if(bc == 1) {
                if(bb == 0) {
                    ans = -1;
                    break;
                } 
            } else {
                if(bb == 0) {
                    ans |= int64_t(1) << i; 
                }
            }
        } else {
            if(bc == 1) {
                if(bb == 1) {
                    ans |= int64_t(1) << i;
                }
            } else {
                if(bb == 1) {
                    ans = -1;
                    break;
                }
            }
        }
    }
    
    std::cout << ans << '\n';
    if(ans != -1) {
        assert((ans | B) - (ans & C) == D);
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
