#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, A, B, C, D;
    std::cin >> N >> A >> B >> C >> D;
    
    int ans = 0;
    if(C >= D) {
        for(int i = 0; i <= N; i++) {
            int x = i * A + (N - i) * B + i * (N - i) * C; 
            ans = std::max(ans, x);
        }    
    } else {
        for(int i = 0; i <= N; i++) {
            int x = i * B + (N - i) * A + i * (N - i) * D;
            ans = std::max(ans, x);
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
