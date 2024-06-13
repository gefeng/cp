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

    std::array<int, 3> a = {A, B, C};
    int ans = 0;
    while(true) {
        std::sort(a.begin(), a.end());
        if(a[1] == 0 || a[2] == 0) {
            break;
        }
        
        a[2] -= 1;
        a[1] -= 1;
        ans += 1;
    }

    for(int i = 0; i < 3; i++) {
        if(a[i] % 2 == 1) {
            std::cout << -1 << '\n';
            return;
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
