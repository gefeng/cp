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

    std::string S;
    std::cin >> S;

    int ans = 1;
    int p = N / 2 + 1;
    while(p < N && S[p] == S[N / 2]) {
        ans += 1;
        p += 1;
    }

    p = N / 2 - 1;
    while(p >= 0 && S[p] == S[N / 2]) {
        ans += 1;
        p -= 1;
    }

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
