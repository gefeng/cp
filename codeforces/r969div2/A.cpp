#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int L, R;
    std::cin >> L >> R;

    if(L % 2 == 0) {
        L += 1;
    }

    int ans = 0;
    for(int i = L; i <= R; ) {
        if(i % 2 == 1 && i + 2 <= R) {
            ans += 1; 
            i += 4;
        } else {
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
