#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> have(N + 1, 1);
    have[0] = 0;
    
    for(int i = 0; i < Q; i++) {
        int X;
        std::cin >> X;

        have[X] ^= 1;
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += have[i];
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
