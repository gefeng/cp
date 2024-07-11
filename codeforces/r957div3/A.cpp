#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::array<int, 3> A = {};
    
    for(int i = 0; i < 3; i++) {
        std::cin >> A[i];
    } 

    for(int i = 0; i < 5; i++) {
        int min_v = 1000;
        int min_p = -1;
        for(int j = 0; j < 3; j++) {
            if(A[j] < min_v) {
                min_v = A[j];
                min_p = j;
            }
        }

        A[min_p] += 1;
    }

    int ans = 1;
    for(int i = 0; i < 3; i++) {
        ans *= A[i];
    }

    std::cout << ans << '\n';
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
