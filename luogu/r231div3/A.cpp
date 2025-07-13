#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X, Y;
    std::cin >> N >> X >> Y;

    int ans = -1;
    for(int i = 0; i < N; i++) {
        int A, B, C;
        std::cin >> A >> B >> C;
        
        if(B == 1 && C == 1) {
            continue;
        }
        if(B) {
            A -= X;
        }
        if(C) {
            A -= Y;
        }
        ans = std::max(ans, A);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
