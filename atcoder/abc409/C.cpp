#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, L;
    std::cin >> N >> L;
    
    std::vector<int> A(N - 1);
    for(int i = 0; i < N - 1; i++) {
        std::cin >> A[i];
    }

    if(L % 3 != 0) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<int> pos(N, 0);
    for(int i = 1; i < N; i++) {
        pos[i] = (pos[i - 1] + A[i - 1]) % L;
    }
    
    std::vector<int> freq(L, 0);
    for(int i = 0; i < N; i++) {
        freq[pos[i]] += 1;
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int l = (pos[i] - L / 3 + L) % L;
        int r = (pos[i] + L / 3) % L;
        ans += int64_t(freq[l]) * freq[r];
    }

    std::cout << ans / 3 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
