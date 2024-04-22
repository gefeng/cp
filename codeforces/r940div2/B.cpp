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

    if(N == 1) {
        std::cout << K << '\n';
        return;
    }
    
    int p2 = 1;
    for(int i = 0; i < 30; i++) {
        if(p2 * 2 > K) {
            break;
        } 
        p2 *= 2;
    }

    std::vector<int> ans(N, 0);
    ans[0] = p2 - 1;
    ans[1] = K - (p2 - 1);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
        sum |= ans[i];
    }
    //std::cout << __builtin_popcount(sum) << '\n';
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
