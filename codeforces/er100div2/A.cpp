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
    if(sum % 9 != 0) {
        std::cout << "NO" << '\n';
        return;
    }

    int x = sum / 9;
    if(A < x || B < x || C < x) {
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
