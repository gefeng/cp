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

    if(K == 0) {
        std::cout << 0 << '\n';
        return;
    }

    if(K <= N) {
        std::cout << 1 << '\n';
        return;
    }

    int ans = 1;
    K -= N;
    for(int i = N - 1; i > 0; i--) { 
        ans += 1;
        if(K <= i) {
            break;
        }
        K -= i;
    
        ans += 1;
        if(K <= i) {
            break;
        }
        K -= i;
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
