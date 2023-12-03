#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

const std::array<int, 8> DR = {0, 1, 0, -1, 1, 1, -1, -1};
const std::array<int, 8> DC = {1, 0, -1, 0, 1, -1, 1, -1};

void run_case1() {
    std::string S;
    std::vector<std::string> G;
    
    while(std::getline(std::cin, S)) {
        G.push_back(S);
    }

    auto is_digit = [](char c) {
        return c >= '0' && c <= '9';
    };

    auto is_symbol = [&](char c) {
        return !is_digit(c) && c != '.';
    };

    int n = G.size();
    int m = G[0].size();
    int64_t ans = 0;
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++) {
            if(is_digit(G[i][j])) {
                int st = j;
                while(j < m && is_digit(G[i][j])) {
                    j += 1;
                }

                bool is_engine_part = false;
                int64_t x = 0;
                for(int k = st; k < j; k++) {
                    x = x * 10 + G[i][k] - '0';
                    for(int d = 0; d < 8; d++) {
                        int nr = i + DR[d];
                        int nc = k + DC[d];
                        if(nr >= 0 && nc >= 0 && nr < n && nc < m && is_symbol(G[nr][nc])) {
                            is_engine_part = true;
                            break;
                        }
                    } 
                } 

                if(is_engine_part) {
                    ans += x; 
                }
            }
        }
    }

    std::cout << ans << '\n';
}

void run_case2() {
    std::string S;
    std::vector<std::string> G;
    
    while(std::getline(std::cin, S)) {
        G.push_back(S);
    }

    auto is_digit = [](char c) {
        return c >= '0' && c <= '9';
    };

    int n = G.size();
    int m = G[0].size();
    int64_t ans = 0;
    std::map<std::pair<int, int>, std::vector<int64_t>> gear;
    
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++) {
            if(is_digit(G[i][j])) {
                int st = j;
                int64_t x = 0;
                while(j < m && is_digit(G[i][j])) {
                    j += 1;
                }

                std::set<std::pair<int, int>> stars;
                for(int k = st; k < j; k++) {
                    x = x * 10 + G[i][k] - '0';
                    for(int d = 0; d < 8; d++) {
                        int nr = i + DR[d];
                        int nc = k + DC[d];
                        if(nr >= 0 && nc >= 0 && nr < n && nc < m && G[nr][nc] == '*') {
                            stars.emplace(nr, nc);
                        }
                    } 
                } 

                for(auto [r, c] : stars) {
                    gear[{r, c}].push_back(x);
                }
            }
        }
    }

    for(auto [p, v] : gear) {
        if(v.size() == 2) {
            ans += v[0] * v[1];
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    //run_case1();
    run_case2();
}
