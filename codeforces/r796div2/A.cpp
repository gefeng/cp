#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X;
    std::cin >> X;

    int ans = 0;
    for(int i = 0; i <= 30; i++) {
        if(X & (1 << i)) {
            ans |= 1 << i; 
            break;
        }
    }

    while(ans == X || (ans & X) == 0) {
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
