#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B, K;
    std::cin >> A >> B >> K;

    int ans = B - A;
    int cur = B;
    int cnt = 0;
    while(cur >= A) {
        int rem = cur % K;
        
        cur = cur / K * K;
        cur /= K;
        cnt += rem + 1;
        
        if(cur >= A) {
            ans = std::min(ans, cur - A + cnt);
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
