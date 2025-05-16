#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int D, K;
    std::cin >> D >> K;

    int64_t lo = 0;
    int64_t hi = D / K;
    int64_t t = 0;

    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
    
        int64_t x = mid * K;
        
        if(x * x + x * x <= int64_t(D) * D) {
            t = mid; 
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    int64_t x = (t + 1) * K;
    if(x <= D && x * x + t * K * t * K <= int64_t(D) * D) {
        std::cout << "Ashish" << '\n';
    } else {
        std::cout << "Utkarsh" << '\n';
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
