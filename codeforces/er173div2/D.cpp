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
    int64_t L, R, G;
    std::cin >> L >> R >> G;
    
    int64_t lb = (L + G - 1) / G;
    int64_t rb = R / G;
    // if(lb * G > R) {
    //     std::cout << -1 << ' ' << -1 << '\n';
    //     return;
    // }
    // if(lb == rb) {
    //     if(lb != 1) {
    //         std::cout << -1 << ' ' << -1 << '\n';
    //         return;
    //     }
    //     std::cout << G << ' ' << G << '\n';
    //     return;
    // }
    //
    // if(gcd(lb, rb) == 1) {
    //     std::cout << lb * G << ' ' << rb * G << '\n'; 
    //     return;
    // }

    int64_t max_d = rb - lb + 1;
    int64_t a = -1;
    int64_t b = -1;
    while(max_d > 0) {
        for(int64_t x = lb; x + max_d - 1 <= rb; x++) {
            if(gcd(x, x + max_d - 1) == 1) {
                a = x * G;
                b = (x + max_d - 1) * G;
                break;
            }
        }

        if(a != -1) {
            break;
        }
        max_d -= 1;
    }

    std::cout << a << ' ' << b << '\n';
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
