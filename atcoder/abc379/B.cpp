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
    for(int i = 0; i <= N - K; ) {
        bool good = true; 
        for(int j = 0; j < K; j++) {
            if(S[i + j] == 'X') {
                good = false;
                break;
            }
        }
        
        if(good) {
            ans += 1;
            i += K;
        } else {
            i += 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
