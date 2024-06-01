#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, L, R;
    std::cin >> N >> L >> R;

    L -= 1;
    R -= 1;

    std::vector<int> ans(N);
    for(int i = 0; i < N; i++) {
        ans[i] = i + 1;
    }

    std::reverse(ans.begin() + L, ans.begin() + R + 1);

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
