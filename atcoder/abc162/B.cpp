#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    int N;
    std::cin >> N;

    LL ans = 0LL;
    for(int i = 1; i <= N; i++) {
        if(i % 3 != 0 && i % 5 != 0) {
            ans += i;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
