#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B, C, D;
    std::cin >> A >> C >> B >> D;

    if(B < D) {
        std::cout << (C <= std::min(A, B) ? "Gellyfish" : "Flower") << '\n';
    } else {
        std::cout << (A >= std::min(C, D) ? "Gellyfish" : "Flower") << '\n';
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
