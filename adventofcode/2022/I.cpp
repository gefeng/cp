#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

const std::array<int, 4> DR = {0, -1, 0, 1};
const std::array<int, 4> DC = {1, 0, -1, 0};

const std::array<int, 4> DIAR = {1, -1, 1, -1};
const std::array<int, 4> DIAC = {1, -1, -1, 1};

bool is_adj(int r1, int c1, int r2, int c2) {
    if(r1 == r2 && c1 == c2) {
        return true;
    }

    for(int i = 0; i < 4; i++) {
        int nr1 = r1 + DR[i];
        int nc1 = c1 + DC[i];
        if(nr1 == r2 && nc1 == c2) {
            return true;
        }

        nr1 = r1 + DIAR[i];
        nc1 = c1 + DIAC[i];
        if(nr1 == r2 && nc1 == c2) {
            return true;
        }
    }

    return false;
}

void run_case() {
    std::string S;
    std::set<std::pair<int, int>> vis;
    std::vector<std::pair<int, int>> rope;
    for(int i = 0; i < 10; i++) {
        rope.emplace_back(0, 0);    
    }

    vis.emplace(0, 0);
    while(std::getline(std::cin, S)) {
        int d = 0;
        if(S[0] == 'R') {
            d = 0; 
        } else if(S[0] == 'D') {
            d = 1;
        } else if(S[0] == 'L') {
            d = 2;
        } else {
            d = 3;
        }

        int steps = stoi(S.substr(2, S.size() - 2));

        for(int i = 0; i < steps; i++) {
            rope[0].first += DR[d];
            rope[0].second += DC[d];

            for(int j = 1; j < 10; j++) {
                if(is_adj(rope[j - 1].first, rope[j - 1].second, rope[j].first, rope[j].second)) {
                    continue;
                }

                int d1 = rope[j - 1].first - rope[j].first;
                int d2 = rope[j - 1].second - rope[j].second;

                if(abs(d1) == 2 || abs(d2) == 2) {
                    if(d1 != 0) {
                        rope[j].first += d1 > 0 ? 1 : -1;
                    }
                    if(d2 != 0) {
                        rope[j].second += d2 > 0 ? 1 : -1;
                    }
                }
            }

            vis.emplace(rope.back().first, rope.back().second);
        } 
    }

    std::cout << vis.size() << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
