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

    int ans = std::max(A, B);
    for(int x = 0; x < A; x++) {
        if((A - x) % (B + x) == 0) {
            ans = x;
            break;
        }
    }

    for(int x = 0; x < B; x++) {
        if((A + x) % (B - x) == 0) {
            ans = std::min(ans, x);
            break;
        }
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
