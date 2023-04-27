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

    int cnt = 0;
    for(int i = 0; i < K; i++) {
        for(int j = i; j < N; j += K) {
            if((A[j] - 1) % K != i) {
                cnt += 1;
            }
        } 
    }

    if(cnt == 0) {
        std::cout << 0 << '\n'; 
    } else if(cnt == 2) {
        std::cout << 1 << '\n';
    } else {
        std::cout << -1 << '\n';
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
