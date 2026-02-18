#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = static_cast<int>(1e9);
constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int64_t, int64_t>> A(N);
    int64_t min1 = INF;
    int64_t min2 = INF;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
        min1 = std::min(min1, -(A[i].first + A[i].second));
        min2 = std::min(min2, -(A[i].first - A[i].second));
    }

    auto query = [](char c, int k) {
        std::cout << "? " << c << ' ' << k << std::endl;
        int64_t Q;
        std::cin >> Q;
        return Q;
    };

    int64_t md1 = 0;
    int64_t md2 = 0;
    for(int i = 0; i < 2; i++) {
        md1 = query('R', MAX);
    }

    for(int i = 0; i < 2; i++) {
        md1 = query('U', MAX);
    }

    for(int i = 0; i < 4; i++) {
        md2 = query('D', MAX);
    } 

    int64_t x = (md1 + md2 - min1 - min2 - 8LL * MAX) / 2;
    int64_t y = md1 - min1 - 4LL * MAX - x;
    
    std::cout << "! " << x << ' ' << y << std::endl;
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
