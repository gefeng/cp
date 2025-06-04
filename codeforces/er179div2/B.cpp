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

    std::vector<int> f(N + 1, 0);
    f[1] = 1;
    f[2] = 2;
    for(int i = 3; i <= N; i++) {
        f[i] = f[i - 2] + f[i - 1];
    }
    
    std::string ans(M, '0');
    for(int i = 0; i < M; i++) {
        int W, L, H;
        std::cin >> W >> L >> H;
        
        if(std::min(W, L) < f[N] || H < f[N]) {
            continue;
        }

        if(f[N] + f[N - 1] <= std::max(W, L)) {
            ans[i] = '1';
            continue;
        } 

        if(f[N - 1] + f[N] <= H) {
            ans[i] = '1';
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
