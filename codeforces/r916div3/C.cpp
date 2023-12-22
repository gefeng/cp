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
    std::vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int max_b = 0;
    int exp = 0;
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        max_b = std::max(max_b, B[i]);
        cnt += 1;
        exp += A[i]; 
        if(cnt <= K) {
            ans = std::max(ans, exp + (K - cnt) * max_b);
        }
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
