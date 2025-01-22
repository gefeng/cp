#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::array<int, 5> A = {};
    
    for(int i = 0; i < 5; i++) {
        if(i == 2) {
            continue;
        }
        std::cin >> A[i];
    }

    auto count = [&]() {
        int cnt = 0;
        for(int i = 0; i < 3; i++) {
            if(A[i] + A[i + 1] == A[i + 2]) {
                cnt += 1;
            }
        } 
        return cnt;
    };

    int ans = 0;
    A[2] = A[0] + A[1];
    ans = std::max(ans, count());
    
    A[2] = A[3] - A[1];
    ans = std::max(ans, count());
    
    A[2] = A[4] - A[3];
    ans = std::max(ans, count());

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
