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

    int ans = 1;
    int i = 30;
    for(; i >= 0; i--) {
        if(X & (1 << i)) {
            break;
        }
    }

    i -= 1;
    for(; i >= 0; i--) {
        if(X & (1 << i)) {
            break;
        }
    }

    i -= 1;
    for(; i >= 0; i--) {
        if(X & (1 << i)) {
            continue;
        }
        ans *= 2;
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
