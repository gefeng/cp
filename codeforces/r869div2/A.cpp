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

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<bool> present(N, true);
    for(int c = 0; c < K; c++) {
        for(int r = 1; r < N; r++) {
            if(!present[r]) {
                continue;
            }

            if(A[r][c] != A[0][c]) {
                present[r] = false; 
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(present[i]) {
            ans += 1;
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
