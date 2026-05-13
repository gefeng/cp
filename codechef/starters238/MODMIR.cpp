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

    if(N == 1) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int> ans(N + 1);
    
    for(int i = 0, j = 0; i < N + 1; i += 3, j ^= 1) {
        ans[i] = 0;
        if(i + 1 < N + 1) {
            ans[i + 1] = j == 0 ? 1 : M - 1;
        }
        if(i + 2 < N + 1) {
            ans[i + 2] = j == 0 ? 1 : M - 1;
        }
    }

    if((ans[N - 1] + 0) % M != ans[N] % M) {
        std::cout << -1 << '\n';
        return;
    }

    for(int i = 1; i <= N; i++) {
        std::cout << ans[i] << " \n"[i == N];
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
