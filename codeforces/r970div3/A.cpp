#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B;
    std::cin >> A >> B;

    if(A == 0 && B == 0) {
        std::cout << "YES" << '\n';
        return;
    }

    if(A == 0) {
        std::cout << (B % 2 == 0 ? "YES" : "NO") << '\n';
        return;
    }
    
    if(B == 0) {
        std::cout << (A % 2 == 0 ? "YES" : "NO") << '\n';
        return;
    }

    if(A % 2 == 1) {
        std::cout << "NO" << '\n';
        return;
    }

    std::cout << "YES" << '\n';
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
