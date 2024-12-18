#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::array<int, 6> A = {};
    int K;
    for(int i = 0; i < 6; i++) {
        std::cin >> A[i];
    }
    std::cin >> K;

    std::array<int, 3> a = {std::abs(A[0] - A[3]), std::abs(A[1] - A[4]), std::abs(A[2] - A[5])};

    std::sort(a.begin(), a.end());
    
    int s_1 = (a.back() + K - 1) / K;
    int s_2 = a[0] + a[1];

    int ans = 0;
    if(s_2 >= s_1) {
        for(int i = 0; i < 3; i++) {
            ans += a[i];
        }
    } else {
        int d = s_1 - s_2;
        if(d % 2 == 1) {
            d -= 1;
        }
        ans = a[0] + a[1] + a[2] + d;
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
