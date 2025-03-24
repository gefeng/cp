#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <tuple>

void run_case() {
    int R, B;
    std::cin >> R >> B;

    if(R % 2 == 1) {
        std::cout << "No" << '\n';
        return;
    }

    int x = 0;
    int y = 0;

    std::vector<std::tuple<int, int, int>> ans;
    if(B == 0) {
        for(int i = 0; i < R / 2; i++) {
            ans.emplace_back(0, x, y++);
        } 
        x += 1;
        y -= 1;
        for(int i = 0; i < R / 2; i++) {
            ans.emplace_back(0, x, y--); 
        }
    } else if(R == 0) {
        if(B % 2 == 1) {
            std::cout << "No" << '\n';
            return;
        }
        x = 0;
        y = 1;
        for(int i = 0; i < B / 2; i++) {
            ans.emplace_back(1, x++, y++);
        }
        y -= 2;
        for(int i = 0; i < B / 2; i++) {
            ans.emplace_back(1, x--, y--);
        } 
    } else {
        x = 0;
        y = 1;
        int nx = 0;
        int ny = 0;

        for(int i = 0; i < B / 2; i++) {
            ans.emplace_back(1, x++, y++);
        }
        ny = y - 2;
        nx = x;

        if(B % 2 == 1) {
            ans.emplace_back(1, x, y);
            x++;
            if(B > 1) {
                y--;
            } else {
                y++;
            }
            for(int i = 0; i < R / 2; i++) {
                ans.emplace_back(0, x++, y);
            }
            x--;
            y--;
            for(int i = 0; i < R / 2; i++) {
                ans.emplace_back(0, x--, y);
            }
        } else {
            for(int i = 0; i < R / 2; i++) {
                ans.emplace_back(0, x++, y);
            }
            x--;
            y--;
            for(int i = 0; i < R / 2; i++) {
                ans.emplace_back(0, x--, y);
            }
        }

        x = nx;
        y = ny;
        for(int i = 0; i < B / 2; i++) {
            ans.emplace_back(1, x--, y--);
        } 
    }

    std::cout << "Yes" << '\n';
    for(auto [c, x, y] : ans) {
        std::cout << (c == 0 ? 'R' : 'B') << ' ' << x + 1 << ' ' << y + 1 << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
