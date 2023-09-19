#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K, X;
    std::cin >> N >> K >> X;
    
    if(K > N || X < K - 1) {
        std::cout << -1 << '\n';
        return;
    }

    int ans = 0;
    for(int i = 0; i < K; i++) {
        ans += i;
    }

    for(int i = K; i < N; i++) {
        ans += (X == K ? X - 1 : X); 
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
