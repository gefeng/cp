#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int K;
    std::cin >> K;

    if(K == 100) {
        std::cout << 1 << '\n';
        return;
    }

    int w = 1;
    while((K * w) % (100 - K) != 0) {
        w += 1;
    }
    
    int e = K * w / (100 - K);
    
    std::cout << e + w << '\n'; 
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
