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

    int ans = A + B / 3;
    
    int rem = B % 3;
    if(rem && rem + C < 3) {
        std::cout << -1 << '\n';
        return;
    }

    if(rem) {
        ans += 1;
        C -= 3 - rem;
    }

    ans += (C + 2) / 3;

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
