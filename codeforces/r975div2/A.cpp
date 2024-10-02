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
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = 0;
    int score = 0;
    int max_v = 0;
    for(int i = 0; i < N; i += 2) {
        max_v = std::max(max_v, A[i]); 
        score += 1;
    }

    score += max_v;
    ans = score;
    
    max_v = 0;
    score = 0;
    for(int i = 1; i < N; i += 2) {
        max_v = std::max(max_v, A[i]); 
        score += 1;
    }

    score += max_v;
    
    ans = std::max(ans, score);
    
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
