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

    std::sort(A.begin(), A.end());

    int score = A.back() + A[N - 2];
    int ans = 0; 
    
    if(N == 2) {
        ans = score * 2;
    } else {
        if(K == 1) {
            ans = score + A.back() + A[0]; 
        }
    
        score += A[0];
        int cnt = N - 2;
        int p = 1;
        while(cnt > K) {
            p += 1;
            cnt -= 1;
        }
        score += A[p];
        
        ans = std::max(ans, score);
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
