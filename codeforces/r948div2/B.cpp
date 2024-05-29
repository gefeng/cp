#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X;
    std::cin >> X;

    std::vector<int> ans(32, 0);
    for(int i = 0; i < 30; i++) {
        if(X & (1 << i)) {
            ans[i] = 1;
        } 
    }

    for(int i = 0; i < 32; ) {
        if(ans[i] == 1) {
            int j = i;
            while(i < 32 && ans[i] == 1) {
                i += 1;
            }
            if(i - j > 1) {
                ans[i] = 1;
                ans[j] = -1;
                for(int k = j + 1; k < i; k++) {
                    ans[k] = 0;
                }
            }
        } else {
            i += 1;
        }
    }

    std::cout << 32 << '\n';
    for(int i = 0; i < 32; i++) {
        std::cout << ans[i] << " \n"[i == 31];
    }
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
