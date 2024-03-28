#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B, C;
    std::cin >> A >> B >> C;
    
    if(A < B && B < C) {
        std::cout << "STAIR" << '\n';
        return;
    }

    if(A < B && B > C) {
        std::cout << "PEAK" << '\n';
        return;
    }

    std::cout << "NONE" << '\n';
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
