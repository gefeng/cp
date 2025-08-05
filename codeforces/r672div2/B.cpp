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

    std::array<int, 30> freq = {};
    
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int hb = -1;
        for(int j = 29; j >= 0; j--) {
            if(A[i] & (1 << j)) {
                hb = j;
                break;
            }
        }

        ans += freq[hb];
        
        freq[hb] += 1;
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
