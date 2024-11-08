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

    if(K > (N - 1) / 2) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int> ans(N, 0);
    for(int i = 1, j = 0, x = N; j < K; i += 2, j++, x--) {
        ans[i] = x; 
    }

    for(int i = 0, j = 1; i < N; i++) {
        if(!ans[i]) {
            ans[i] = j++;
        }
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
