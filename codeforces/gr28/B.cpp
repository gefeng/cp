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
    
    std::vector<int> ans(N, 0);
    int j = 1;
    for(int i = K - 1; i < N; i += K) {
        ans[i] = j++; 
    }

    for(int i = 0; i < N; i++) {
        if(ans[i] == 0) {
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
