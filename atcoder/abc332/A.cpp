#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, S, K;
    std::cin >> N >> S >> K;;

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int P, Q;
        std::cin >> P >> Q;

        ans += P * Q;
    }

    if(ans < S) {
        ans += K;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
