#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::array<int, 7> A{};
    for(int i = 0; i < 7; i++) {
        std::cin >> A[i];
    }

    int ans = 0;
    std::ranges::sort(A);

    for(int i = 0; i < 6; i++) {
        ans += -A[i];
    }
    ans += A.back();

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
