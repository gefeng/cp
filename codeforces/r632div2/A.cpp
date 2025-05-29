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

    std::vector<std::string> ans(N, std::string(M, 'W'));
    for(int i = 0; i < N; i++) {
        for(int j = i % 2 == 0 ? 0 : 1; j < M; j += 2) {
            ans[i][j] = 'B';
        } 
    }

    if((N * M) % 2 == 0) {
        ans[0][1] = 'B';
    }
    
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << '\n';
    }
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
