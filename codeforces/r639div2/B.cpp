#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    auto count = [](int x) {
        int res = 0;
        for(int i = 1; i <= x; i++) {
            int64_t need = int64_t(i + 1) * i / 2 * 2 + int64_t(i) * (i - 1) / 2;
            if(need <= x) {
                res = need; 
            } else {
                break;
            }
        } 
        return res;
    };

    int ans = 0;
    while(true) {
        int cnt = count(N);
        
        if(cnt == 0) {
            break;
        }

        ans += 1;
        N -= cnt;
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
