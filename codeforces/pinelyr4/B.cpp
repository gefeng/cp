#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> B(N - 1);
    for(int i = 0; i < N - 1; i++) {
        std::cin >> B[i];
    }

    std::vector<int> ans(N);
    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < 30; j++) {
            if(B[i] & (1 << j)) {
                ans[i] |= 1 << j;
                ans[i + 1] |= 1 << j;
            }
        }
    }

    for(int i = 0; i < N - 1; i++) {
        if((ans[i] & ans[i + 1]) != B[i]) {
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
