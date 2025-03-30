#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;

int64_t q_pow(int64_t x, int64_t y) {
    int64_t res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

void run_case() {
    int64_t N, M, K;
    std::cin >> N >> M >> K;

    auto is_border_cell = [&](int x, int y) {
        if((x == 1 && y == 1) || (x == 1 && y == M) || (x == N && y == 1) || (x == N && y == M)) {
            return false;
        }
        return x == 1 || y == 1 || x == N || y == M;
    };

    int64_t tot = (N - 2) * 2 + (M - 2) * 2;
    int64_t cnt_black = 0;  // # border cells painted black excluding corners
    int64_t cnt_border = 0; // # painter border cells excluding corners
    for(int i = 0; i < K; i++) {
        int X, Y, C;
        std::cin >> X >> Y >> C;

        if(is_border_cell(X, Y)) {
            cnt_border += 1;
            if(C) {
                cnt_black += 1; 
            }
        }
    }

    if(tot == cnt_border) {
        std::cout << (cnt_black % 2 == 0 ? q_pow(2, N * M - K) : 0) << '\n';
        return;
    }

    std::cout << q_pow(2, N * M - K - 1) << '\n';
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
