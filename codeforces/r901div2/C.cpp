#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    int64_t ans = 0;
    if(N % M == 0) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<int64_t> psum(30, 0);
    psum[0] = 1;
    for(int i = 1; i < 30; i++) {
        psum[i] = psum[i - 1] + (1 << i);
    }

    N = N % M;
    while(N) {
        int x = M;
        
        int cnt = 0;
        while(x % 2 == 0 && x > N) {
            x /= 2; 
            cnt += 1;
        }

        if(x > N) {
            std::cout << -1 << '\n';
            return;
        }

        N -= x;
        ans += x * psum[cnt - 1];
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
