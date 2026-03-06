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

    int64_t ans = 1;
    for(int f = 2; f * f <= N; f++) {
        if(N % f == 0) {
            while(N % f == 0) {
                N /= f;
            }
            ans *= f; 
        }
    }
    if(N > 1) {
        ans *= N;
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
