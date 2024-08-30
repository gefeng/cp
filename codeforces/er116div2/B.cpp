#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N, K;
    std::cin >> N >> K;
    
    int64_t ans = 0;
    int64_t need = 1;
    N -= 1;

    while(N > 0) {
        if(need == K) {
            ans += (N + K - 1) / K;
            break;
        }

        ans += 1;
        N -= need; 
        if(need * 2 <= K) {
            need *= 2;
        } else {
            need = K;
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
