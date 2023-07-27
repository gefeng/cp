#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int B, C, H;
    std::cin >> B >> C >> H;

    int x = C + H;
    int ans = 0;
    while(true) {
        if(B == 0) {
            break;
        }
        B -= 1;
        ans += 1;
        if(x == 0 || B == 0) {
            break;
        }
        
        x -= 1;
        ans += 1;
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
