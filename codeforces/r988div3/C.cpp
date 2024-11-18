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
    
    if(N < 5) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int> ans(N);
    int p = 0;
    for(int j = 1; j <= N; j += 2) {
        if(j != 5) {
            ans[p++] = j; 
        }
    }

    ans[p++] = 5;
    ans[p++] = 4;
    
    for(int j = 2; j <= N; j += 2) {
        if(j != 4) {
            ans[p++] = j;
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
