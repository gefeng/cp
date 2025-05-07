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

    std::vector<int> ans(N);
    
    int x = K - N + 2;
    if(x < 1) {
        std::cout << -1 << '\n';
        return;
    }

    ans[0] = x;
    ans[1] = 2 * x;
    
    for(int i = 2; i < N; i++) {
        ans[i] = ans[i - 1] + 1;
    }  

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
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
