#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> freq(N + 1, 0);
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int X;
        std::cin >> X;
        ans = std::max(ans, ++freq[X]); 
    }

    std::cout << N - ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
