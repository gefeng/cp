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

    if(A > B) {
        std::cout << ((A - B) % 2 == 0 ? 1 : 2) << '\n';
    } else {
        std::cout << ((B - A) % 2 == 0 ? 2 : 1) << '\n';
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
