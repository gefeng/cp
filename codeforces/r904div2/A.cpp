#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X, K;
    std::cin >> X >> K;

    int ans = 0;
    for(int i = 0; i < 20; i++) {
        int x = X + i;
        int sum = 0;
        while(x) {
            sum += x % 10;
            x /= 10;
        }

        if(sum % K == 0) {
            ans = X + i;
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
