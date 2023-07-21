#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::array<int, 3> A;

    int sum = 0;
    for(int i = 0; i < 3; i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    for(int i = 0; i < 3; i++) {
        if(sum - A[i] >= 10) {
            std::cout << "YES" << '\n';
            return;
        }
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
