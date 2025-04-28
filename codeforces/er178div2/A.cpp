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

    int sum = A + B + C;
    
    if(sum % 3 != 0) {
        std::cout << "No" << '\n';
        return;
    }

    int t = sum / 3;

    int need_a = t - A;
    int need_b = t - B;

    if(need_a < 0 || need_b < 0) {
        std::cout << "No" << '\n';
        return;
    }

    C -= need_a;
    C -= need_b;
    
    std::cout << (C == t ? "Yes" : "No") << '\n';
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
