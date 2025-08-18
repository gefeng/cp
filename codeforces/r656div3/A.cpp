#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X, Y, Z;
    std::cin >> X >> Y >> Z;
    
    if(X == Y && Y == Z) {
        std::cout << "YES" << '\n';
        std::cout << X << ' ' << Y << ' ' << Z << '\n';
        return;
    }

    if(X != Y && Y != Z && X != Z) {
        std::cout << "NO" << '\n';
        return;
    }

    int max_v = std::max(std::max(X, Y), Z);
    int min_v = std::min(std::min(X, Y), Z);

    if(X == max_v && Y == max_v) {
        std::cout << "YES" << '\n';
        std::cout << max_v << ' ' << min_v << ' ' << min_v << '\n';
        return;
    }
    
    if(X == max_v && Z == max_v) {
        std::cout << "YES" << '\n';
        std::cout << min_v << ' ' << max_v << ' ' << min_v << '\n';
        return;
    }

    if(Y == max_v && Z == max_v) {
        std::cout << "YES" << '\n';
        std::cout << min_v << ' ' << min_v << ' ' << max_v << '\n';
        return;
    }

    std::cout << "NO" << '\n';
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
