#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X, Y;
    std::cin >> X >> Y;

    int ans = 0;
    for(int i = 0; i <= 30; i++) {
        int b1 = X & (1 << i) ? 1 : 0;
        int b2 = Y & (1 << i) ? 1 : 0;
        if(b1 != b2) {
            ans = 1 << i;
            break;
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
