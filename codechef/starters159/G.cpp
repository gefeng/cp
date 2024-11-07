#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N, M, K;
    std::cin >> N >> M >> K;

    std::string S;
    std::cin >> S;

    int64_t rounds = std::min(N, M);
    
    int64_t cnt_a = 0;
    int64_t cnt_b = 0;
    int64_t ra = 0;
    int64_t rb = 0;
    for(int i = 0; i < K; i++) {
        if(S[i] == 'A') {
            cnt_a += 1;
            ra += i;
        } else {
            cnt_b += 1;
            rb += i;
        }
    }

    int64_t t = rounds / K; 
    int64_t rem = rounds % K;

    auto f1 = [&]() {
        int64_t x = N + M - 1;
        int64_t y = cnt_a * t;
        for(int i = 0; i < rem; i++) {
            if(S[i] == 'A') {
                y += 1;
            }
        }
        return x * y;
    };

    auto f2 = [&]() {
        int64_t x = ra * t;
        int64_t y = K * cnt_a;
        x += (y + (t - 1) * y) * (t - 1) / 2;
        for(int i = 0; i < rem; i++) {
            if(S[i] == 'A') {
                x += i + t * K;
            }
        }
        return x * 2;
    };

    auto f3 = [&](int flag) {
        int64_t pre_a = 0;
        int64_t pre_b = 0;
        int64_t cnt = 0;
        for(int i = 0; i < K; i++) {
            if(S[i] == 'B') {
                cnt += 1;
            } else {
                pre_b += cnt;
            }
        }

        int64_t x = cnt * cnt_a;
        pre_b = pre_b * t;
        pre_b += (x + (t - 1) * x) * (t - 1) / 2;
        int64_t tmp = cnt;
        cnt = 0;
        for(int i = 0; i < rem; i++) {
            if(S[i] == 'B') {
                cnt += 1;
            } else {
                pre_b += cnt + t * tmp;
            }
        }

        cnt = 0;
        for(int i = 0; i < K; i++) {
            if(S[i] == 'A') {
                cnt += 1;
            } else {
                pre_a += cnt;
            }
        }

        x = cnt * cnt_b;
        pre_a = pre_a * t;
        pre_a += (x + (t - 1) * x) * (t - 1) / 2;
        tmp = cnt;
        cnt = 0;
        for(int i = 0; i < rem; i++) {
            if(S[i] == 'A') {
                cnt += 1;
            } else {
                pre_a += cnt + t * tmp;
            }
        }

        return flag ? (pre_a - pre_b) * 2 : (pre_b - pre_a) * 2;
    };

    auto g1 = [&]() {
        int64_t x = N + M - 1;
        int64_t y = cnt_b * t;
        for(int i = 0; i < rem; i++) {
            if(S[i] == 'B') {
                y += 1;
            }
        }
        return x * y;
    };

    auto g2 = [&]() {
        int64_t x = rb * t;
        int64_t y = K * cnt_b;
        x += (y + (t - 1) * y) * (t - 1) / 2;
        for(int i = 0; i < rem; i++) {
            if(S[i] == 'B') {
                x += i + t * K;
            }
        }
        return x * 2;
    };

    auto solve_a = [&]() {
        return f1() - f2() + f3(0);
    };

    auto solve_b = [&]() {
        return g1() - g2() + f3(1);
    };

    int64_t a = solve_a();
    int64_t b = solve_b();
    if(a == b) {
        std::cout << "Draw" << '\n';
        return;
    }

    std::cout << (a > b ? "Alice" : "Bob") << '\n';
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
