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

    std::string S;
    std::cin >> S;

    int ans = 0;
    for(int i = 0; i < (K + 1) / 2; i++) {
        std::array<int, 26> freq = {};
        for(int j = 0; j < N; j += K) {
            freq[S[i + j] - 'a'] += 1; 
            freq[S[K - 1 - i + j] - 'a'] += 1;
        } 

        int max_v = 0;
        for(int j = 0; j < 26; j++) {
            max_v = std::max(max_v, freq[j]); 
        }
        
        if(K % 2 == 1 && i == K / 2) {
            ans += N / K - max_v / 2;
        } else {
            ans += N / K * 2 - max_v;
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
