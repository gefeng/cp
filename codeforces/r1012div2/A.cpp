#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X, Y, A;
    std::cin >> X >> Y >> A;
    
    int rem = A % (X + Y);
    if(X > rem) {
        std::cout << "NO" << '\n';
    } else {
        std::cout << "YES" << '\n';
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
