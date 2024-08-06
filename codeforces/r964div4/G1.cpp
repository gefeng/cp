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
        int mid = (lo + hi) >> 1;
        
        int a = mid;
        int b = 999;
        int s1 = a * (b + 1);
        int s2 = query(a, b);
        
        if(s1 == s2) {
            lo = mid + 1;
        } else {
            ans = mid;
            hi = mid - 1;
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
