#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N, X, Y;
    std::cin >> N >> X >> Y;

    std::string S;
    std::cin >> S;
    
    int cnt = std::ranges::count(S, '4');

    if(std::abs(X) > N || std::abs(Y) > N) {
        std::cout << "NO" << '\n';
        return;
    }

    int64_t d = std::max(static_cast<int64_t>(0), cnt - N + std::abs(X));
    std::cout << (std::abs(Y) <= N - d ? "YES" : "NO") << '\n';
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
