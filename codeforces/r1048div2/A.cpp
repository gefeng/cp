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

    if(A == B) {
        std::cout << 0 << '\n';
        return;
    }

    if(A % B == 0 || B % A == 0) {
        std::cout << 1 << '\n';
        return;
    }

    std::cout << 2 << '\n';
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
