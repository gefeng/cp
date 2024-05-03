#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int X;
    std::cin >> X;

    int max_v = 0;
    int ans = 0;
    for(int y = 1; y < X; y++) {
        int z = gcd(X, y) + y; 
        if(z > max_v) {
            max_v = z;
            ans = y;
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
