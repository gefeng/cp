#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    int64_t SX, SY;
    std::cin >> N >> SX >> SY;
    
    std::vector<int64_t> X(N);
    std::vector<int64_t> Y(N);
    for(int i = 0; i < N; i++) {
        std::cin >> X[i] >> Y[i];
    }

    auto f = [](int64_t x, int64_t y) {
        return x * x + y * y;
    };

    auto play = [&](int first, int take_odd) {
        std::vector<std::set<int>> v(2);
        for(int i = 0; i < N; i++) {
            v[f(X[i], Y[i]) % 2].insert(i);
        }

        int t = first;
        for(int i = 0; i < N; i++) {
            if(t) {
                if(!v[take_odd].empty()) {
                    int p = *v[take_odd].begin();
                    std::cout << p + 1 << std::endl; 
                    v[take_odd].erase(p);
                } else {
                    int p = *v[take_odd ^ 1].begin();
                    std::cout << p + 1 << std::endl;
                    v[take_odd ^ 1].erase(p);
                }
            } else {
                int P;
                std::cin >> P;
                P -= 1;
                v[f(X[P], Y[P]) % 2].erase(P);
            }
            t ^= 1;
        }
        std::cout << std::endl;
    };

    if(f(SX, SY) % 2 == 0) {
        int cnt_odd = 0;
        for(int i = 0; i < N; i++) {
            if(f(X[i], Y[i]) % 2 == 1) {
                cnt_odd += 1;
            }
        }

        if(cnt_odd <= N / 2) {
            std::cout << "First" << std::endl;
            play(1, 1);
        } else {
            std::cout << "Second" << std::endl;
            play(0, 0);
        }
    } else {
        int cnt_eve = 0;
        for(int i = 0; i < N; i++) {
            if(f(X[i], Y[i]) % 2 == 0) {
                cnt_eve += 1;
            }
        }

        if(cnt_eve <= N / 2) {
            std::cout << "First" << std::endl;
            play(1, 0);
        } else {
            std::cout << "Second" << std::endl;
            play(0, 1);
        }
    }
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
