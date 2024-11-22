#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int64_t N;
    std::cin >> N;

    int64_t ans = N;
    while(true) {
        int sum = 0;
        int64_t x = ans;
        while(x) {
            sum += x % 10;
            x /= 10;
        }
        
        if(gcd(ans, sum) > 1) {
            std::cout << ans << '\n';
            return;
        }

        ans += 1;
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
