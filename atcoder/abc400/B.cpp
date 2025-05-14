#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = int64_t(1e9);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    int64_t ans = 0;
    int64_t now = 1;
    for(int i = 0; i <= M; i++) {
        if(i == 0) {
            ans += now;
        } else {
            now *= N;
            ans += now;
        }
        if(ans > MAX) {
            std::cout << "inf" << '\n';
            return;
        }
    } 

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
