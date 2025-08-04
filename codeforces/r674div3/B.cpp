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

    int ans = 0;
    for(int i = 0; i < N * 2; i += 2) {
        int A, B, C, D;
        std::cin >> A >> B >> C >> D;
        
        if(B == C) {
            ans = 1;
        }
    }

    if(M % 2 == 1) {
        std::cout << "NO" << '\n';
        return;
    }

    std::cout << (ans ? "YES" : "NO") << '\n';
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
