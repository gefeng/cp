#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    auto query = [&](int i) {
        std::cout << "? " << i + 1 << std::endl;
        int res;
        std::cin >> res;
        return res;
    };
    
    int cnt = N / K;
    int rem = N % K;
    int ans = 0;

    if(rem == 0) {
        for(int i = 0; i < cnt; i++) {
            ans ^= query(i * K);
        }
    } else {
        for(int i = 0; i < cnt - 1; i++) {
            ans ^= query(i * K);
        }
        
        int d = rem / 2;
        for(int i = 0; i < 3; i++) {
            ans ^= query(N - K - rem + i * d); 
        }
    }

    std::cout << "! " << ans << std::endl;
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
