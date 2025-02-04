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
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = 1;
    if(N == K) {
        for(int i = 1; i < N; i += 2) {
            if(A[i] != ans) {
                break;
            }
            ans += 1;
        } 
        std::cout << ans << '\n';
    } else {
        for(int i = 1; i < N; i++) {
            if(A[i] != 1 && N - 1 - i >= K - 2) {
                std::cout << 1 << '\n';
                return;
            } 
        }
        
        std::cout << 2 << '\n';
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
