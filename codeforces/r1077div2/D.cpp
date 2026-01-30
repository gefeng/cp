#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int X, Y;
    std::cin >> X >> Y;

    auto solve = [](int t, int x) {
        // find y close to t and not share bits with x

        int64_t best = INF;
        int64_t d = 0;
        int y = 0;

        if((t & x) == 0) {
            y = t;
            best = 0;
        } else {
            int hb = -1;
            for(int i = 30; i >= 0; i--) {
                if(t & (1 << i)) {
                    hb = i;
                    break;
                }
            }

            {
                for(int i = 31; i > hb; i--) {
                    int cand = 1 << i;
                    if((x & cand) == 0) {
                        d = std::abs(cand - t);
                        if(d < best) {
                            best = d;
                            y = cand;
                        }
                    }
                }
            }

            {
                int cand = 0;
                for(int i = hb; i >= 0; i--) {
                    if(x & (1 << i)) {
                        continue;
                    }
                    if((cand | (1 << i)) > t) {
                        cand |= 1 << i;
                        d = std::abs(cand - t);
                        if(d < best) {
                            best = d;
                            y = cand;
                        }
                        cand ^= 1 << i;
                    } else {
                        cand |= 1 << i;
                        d = std::abs(cand - t);
                        if(d < best) {
                            best = d;
                            y = cand;
                        }
                    }
                }
                d = std::abs(cand - t);
                if(d < best) {
                    best = d;
                    y = cand;
                }
            }
        }

        return std::pair<int64_t, int>(best, y);
    };

    int p = 0;
    int q = 0;
    int64_t min_v = INF;
    
    {
        int x = X;
        auto [d, y] = solve(Y, x);
        if(d < min_v) {
            min_v = d;
            p = x;
            q = y;
        }
    }

    {
        int y = Y;
        auto [d, x] = solve(X, y);
        if(d < min_v) {
            min_v = d;
            p = x;
            q = y;
        }
    }

    std::cout << p << ' ' << q << '\n';
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
