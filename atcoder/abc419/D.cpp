#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::string S, T;
    std::cin >> S >> T;;
    
    std::vector<int> diff(N + 1, 0);
    for(int i = 0; i < M; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;
        
        diff[L] ^= 1;
        diff[R + 1] ^= 1;
    }

    int rolling = 0;
    for(int i = 0; i < N; i++) {
        rolling ^= diff[i]; 
        if(rolling) {
            S[i] = T[i];
        }
    }

    std::cout << S << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
