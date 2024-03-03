#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

void run_case() {
    int V1, V2, V3;
    std::cin >> V1 >> V2 >> V3;

    auto overlap2 = [](int x1, int y1, int x2, int y2) {
        if(y1 <= x2 || x1 >= y2) {
            return std::pair<int, int>(INF, INF);
        }
        return std::pair<int, int>(std::max(x1, x2), std::min(y1, y2));
    };

    auto overlap3 = [&](int x1, int y1, int x2, int y2, int x3, int y3) {
        auto [l1, r1] = overlap2(x1, y1, x2, y2);
        auto [l2, r2] = overlap2(l1, r1, x3, y3); 
        return std::pair<int, int>(l2, r2);
    };

    auto area3 = [&](int a1, int b1, int c1, int a2, int b2, int c2) {
        int v = 0;
        auto [lx, rx] = overlap3(0, 7, a1, a1 + 7, a2, a2 + 7);
        auto [ly, ry] = overlap3(0, 7, b1, b1 + 7, b2, b2 + 7);
        auto [lz, rz] = overlap3(0, 7, c1, c1 + 7, c2, c2 + 7);
        if(lx != INF && ly != INF && lz != INF) {
            v = (rx - lx) * (ry - ly) * (rz - lz);
        }
        return v;
    };

    auto area2 = [&](int a1, int b1, int c1, int a2, int b2, int c2, int v) {
        std::array<int, 4> res = {};
        // 1, 2
        std::pair<int, int> sx = overlap2(0, 7, a1, a1 + 7);
        std::pair<int, int> sy = overlap2(0, 7, b1, b1 + 7);
        std::pair<int, int> sz = overlap2(0, 7, c1, c1 + 7);
        int v1 = (sx.second - sx.first) * (sy.second - sy.first) * (sz.second - sz.first);
        res[0] = v1; 
        v1 -= v;

        // 1, 3
        sx = overlap2(0, 7, a2, a2 + 7); 
        sy = overlap2(0, 7, b2, b2 + 7); 
        sz = overlap2(0, 7, c2, c2 + 7); 
        int v2 = (sx.second - sx.first) * (sy.second - sy.first) * (sz.second - sz.first);
        res[1] = v2;
        v2 -= v;

        // 2, 3
        sx = overlap2(a1, a1 + 7, a2, a2 + 7); 
        sy = overlap2(b1, b1 + 7, b2, b2 + 7); 
        sz = overlap2(c1, c1 + 7, c2, c2 + 7); 
        int v3 = (sx.second - sx.first) * (sy.second - sy.first) * (sz.second - sz.first);
        res[2] = v3;
        v3 -= v;

        res[3] = v1 + v2 + v3;
        return res;
    };

    auto area1 = [&](int a1, int b1, int c1, int a2, int b2, int c2, int s1, int s2, int s3, int s) {
        int x = 7 * 7 * 7 * 3;
        int v = x;
        v -= (s1 + s2) - s;
        v -= (s1 + s3) - s;
        v -= (s2 + s3) - s;
        return v;
    };

    for(int a1 = 0; a1 <= 7; a1++) {
        for(int b1 = 0; b1 <= 7; b1++) {
            for(int c1 = 0; c1 <= 7; c1++) {
                for(int a2 = -7; a2 <= 14; a2++) {
                    for(int b2 = -7; b2 <= 14; b2++) {
                        for(int c2 = -7; c2 <= 14; c2++) {
                            int v3 = area3(a1, b1, c1, a2, b2, c2);
                            std::array<int, 4> v2 = area2(a1, b1, c1, a2, b2, c2, v3);
                            int v1 = area1(a1, b1, c1, a2, b2, c2, v2[0], v2[1], v2[2], v3);
                            
                            if(v1 == V1 && v2[3] == V2 && v3 == V3) {
                                std::cout << "Yes" << '\n';
                                std::cout << 0 << ' ' << 0 << ' ' << 0 << ' ' << a1 << ' ' << b1 << ' ' << c1 << ' ' << a2 << ' ' << b2 << ' ' << c2 << '\n';
                                return;
                            }
                        }
                    }
                } 
            }
        }
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
