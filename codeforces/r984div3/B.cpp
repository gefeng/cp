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
    
    std::vector<int> price(K + 1, 0);
    for(int i = 0; i < K; i++) {
        int B, C;
        std::cin >> B >> C;
        
        price[B] += C;
    } 

    std::sort(price.begin(), price.end(), std::greater<int>());
    
    int64_t ans = 0;
    for(int i = 0; i < std::min(N, K + 1); i++) {
        ans += price[i];
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
