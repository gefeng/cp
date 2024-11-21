#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::array<int, 4> A = {};
    for(int i = 0; i < 4; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    std::array<int, 4> cnt = {};
    for(int x : A) {
        cnt[x] += 1;
    }

    int ans = 0;
    for(int x : cnt) {
        ans += x / 2;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
