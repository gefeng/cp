#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X, Y, K;
    std::cin >> X >> Y >> K;

    if(X >= K && Y >= K) {
        std::cout << 0 << ' ' << 0 << ' ' << X << ' ' << 0 << '\n';
        std::cout << 0 << ' ' << 0 << ' ' << 0 << ' ' << Y << '\n';
    } else {
        if(Y > X) {
            std::cout << 0 << ' ' << 0 << ' ' << X << ' ' << X << '\n';
            std::cout << X << ' ' << 0 << ' ' << 0 << ' ' << X << '\n'; 
        } else {
            std::cout << 0 << ' ' << 0 << ' ' << Y << ' ' << Y << '\n';
            std::cout << Y << ' ' << 0 << ' ' << 0 << ' ' << Y << '\n'; 
        }
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
