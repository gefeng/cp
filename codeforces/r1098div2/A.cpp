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

    std::vector<int> A(N);
    std::array<int, 3> freq{};
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        freq[A[i]]++;
    }

    int ans = freq[0];
    int d = std::min(freq[1], freq[2]);
    ans += d;
    freq[1] -= d;
    freq[2] -= d;
    
    ans += freq[1] / 3 + freq[2] / 3;

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
