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
    int N;
    std::cin >> N;

    std::vector<int64_t> X(N);
    std::vector<int64_t> Y(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> X[i] >> Y[i];
    }

    int64_t SX, SY, TX, TY;
    std::cin >> SX >> SY >> TX >> TY;
    
    auto dist = [](int64_t x1, int64_t y1, int64_t x2, int64_t y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    };

    for(int i = 0; i < N; i++) {
        int64_t d1 = dist(SX, SY, TX, TY); 
        int64_t d2 = dist(X[i], Y[i], TX, TY);
        
        if(d2 <= d1) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::cout << "Yes" << '\n';
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
