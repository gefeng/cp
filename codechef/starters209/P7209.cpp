#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::array<std::array<int, 2>, 2> A = {};

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            std::cin >> A[i][j];
        }
    }

    auto solve = [&](std::array<std::array<int, 2>, 2> a) {
        int ans = 0;
        int sum = a[0][0] + a[1][1];
        int x = std::min(a[0][1], a[1][0]);        
        int d = std::min(x, sum - 1);   

        x -= d;
        sum -= d;
        
        if(x) {
            ans = x;
        }
        return ans;
    };

    auto rotate = [&]() {
        int tmp = A[1][1];
        A[1][1] = A[0][1];
        A[0][1] = A[0][0];
        A[0][0] = A[1][0];
        A[1][0] = tmp;
    };

    int ans = 0;
    for(int i = 0; i < 4; i++) {
        ans = std::max(ans, solve(A));
        rotate();
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
