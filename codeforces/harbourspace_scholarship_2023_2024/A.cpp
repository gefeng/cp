#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X, Y, N;
    std::cin >> X >> Y >> N;

    std::vector<int> ans(N);
    ans[0] = X;
    ans[N - 1] = Y;
    
    for(int i = N - 2, j = 1; i > 0; i--, j++) {
        ans[i] = ans[i + 1] - j; 
    }
    
    for(int i = 1; i < N; i++) {
        if(ans[i] <= ans[i - 1]) {
            std::cout << -1 << '\n';
            return;
        }
    }

    for(int i = 2; i < N; i++) {
        if(ans[i - 1] - ans[i - 2] <= ans[i] - ans[i - 1]) {
            std::cout << -1 << '\n';
            return;
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
