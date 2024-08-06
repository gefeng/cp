#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    auto query = [](int a, int b) {
        std::cout << "? " << a << ' ' << b << std::endl;
        int Q;
        std::cin >> Q;
        return Q;
    };

    int lo = 2;
    int hi = 999;
    int ans = 0;
    while(lo <= hi) {
        int a = lo + (hi - lo) / 3;
        int b = hi - (hi - lo) / 3;
        
        int s = query(a, b);
        
        if(s == a * b) {
            lo = b + 1;
        } else if(s == (a * (b + 1))) {
            ans = b;
            lo = a + 1;
            hi = b - 1;
        } else {
            ans = a;
            hi = a - 1;
        }
    }

    std::cout << "! " << ans << std::endl;
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
