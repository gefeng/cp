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
    std::string S;
    int cycle = 0;
    int x = 1;
    int ans = 0;
    std::set<int> target = {20, 60, 100, 140, 180, 220};

    while(std::getline(std::cin, S)) {
        if(S == "noop") {
            for(int i = 0; i < 1; i++) {
                cycle += 1;
                if(target.find(cycle) != target.end()) {
                    ans += x * cycle;
                }
            }
        } else {
            for(int i = 0; i < 2; i++) {
                cycle += 1;
                if(target.find(cycle) != target.end()) {
                    ans += x * (cycle);
                }
            }

            x += stoi(S.substr(5, S.size() - 5));
        }
    }

    std::cout << ans << '\n';
}

void solve2() {
    std::string S;
    int cycle = 0;
    int x = 1;
    std::set<int> target = {20, 60, 100, 140, 180, 220};

    int s_pos = 2;
    int d_pos = 1;
    int r = 0;
    std::vector<std::string> ans(6);;

    auto cover = [](int p1, int p2) {
        return p2 >= p1 - 1 && p2 <= p1 + 1; 
    };

    while(std::getline(std::cin, S)) {
        if(S == "noop") {
            if(cover(s_pos, d_pos)) {
                ans[r].push_back('#'); 
            } else {
                ans[r].push_back('.');
            }
            d_pos += 1;
            if(d_pos > 40) {
                d_pos = 1;
                r += 1;
            }
        } else {
            for(int i = 0; i < 2; i++) {
                if(cover(s_pos, d_pos)) {
                    ans[r].push_back('#'); 
                } else {
                    ans[r].push_back('.');
                }
                d_pos += 1;
                if(d_pos > 40) {
                    d_pos = 1;
                    r += 1;
                }
            }

            s_pos += stoi(S.substr(5, S.size() - 5));
        }
    }

    for(int i = 0; i < 6; i++) {
        std::cout << ans[i] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    //run_case();
    solve2();
}
