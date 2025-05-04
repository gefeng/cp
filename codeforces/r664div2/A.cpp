#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::array<int, 4> A = {};
    
    for(int i = 0; i < 4; i++) {
        std::cin >> A[i];
    }
    
    if(A[0] == 0 || A[1] == 0 || A[2] == 0) {
        int cnt = 0;
        for(int i = 0; i < 4; i++) {
            cnt += A[i] % 2;
        }
        std::cout << (cnt <= 1 ? "Yes" : "No") << '\n';
        return;
    }

    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        cnt += A[i] % 2;
    }

    std::cout << (cnt == 2 ? "No" : "Yes") << '\n';
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
