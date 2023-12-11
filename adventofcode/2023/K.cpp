#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MUL = (int64_t)1e6;

std::vector<std::string> G;

void run_case1() {
    int n = G.size();
    int m = G[0].size();
    
    std::vector<int> expand_col(m, 0);
    
    for(int c = 0; c < m; c++) {
        bool expand = true;
        for(int r = 0; r < n; r++) {
            if(G[r][c] != '.') {
                expand = false;
                break;
            }
        }

        if(expand) {
            expand_col[c] = 1;
        }
    }

    std::vector<std::string> g;
    for(int r = 0; r < n; r++) {
        bool expand = true;
        for(int c = 0; c < m; c++) {
            if(G[r][c] != '.') {
                expand = false;
                break;
            } 
        }

        std::string s = "";
        for(int c = 0; c < m; c++) {
            if(expand_col[c]) {
                s.push_back('.');
                s.push_back('.');
            } else {
                s.push_back(G[r][c]);
            }
        }

        g.push_back(s);
        if(expand) {
            g.push_back(s);
        }
    }

    n = g.size();
    m = g[0].size();
    std::vector<std::pair<int, int>> v;
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            if(g[r][c] == '#') {
                v.emplace_back(r, c); 
            }
        }
    }

    int size = v.size();
    int64_t ans = 0;
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            ans += std::abs(v[i].first - v[j].first) + std::abs(v[i].second - v[j].second);
        }
    }

    std::cout << ans << '\n';
}

void run_case2() {
    int n = G.size();
    int m = G[0].size();
    std::vector<int> expand_row;
    std::vector<int> expand_col;
    
    for(int r = 0; r < n; r++) {
        bool expand = true;
        for(int c = 0; c < m; c++) {
            if(G[r][c] != '.') {
                expand = false;
                break;
            } 
        }

        if(expand) {
            expand_row.push_back(r);
        }
    }

    for(int c = 0; c < m; c++) {
        bool expand = true;
        for(int r = 0; r < n; r++) {
            if(G[r][c] != '.') {
                expand = false;
                break;
            }
        }

        if(expand) {
            expand_col.push_back(c);
        }
    }

    std::vector<std::pair<int, int>> v;
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            if(G[r][c] == '#') {
                v.emplace_back(r, c);
            }
        }
    }
    
    int size = v.size();
    int64_t ans = 0;
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            auto [r1, c1] = v[i];
            auto [r2, c2] = v[j]; 
            int64_t dr = std::abs(r1 - r2);
            int64_t dc = std::abs(c1 - c2);

            auto it1 = std::upper_bound(expand_row.begin(), expand_row.end(), r1);
            auto it2 = std::upper_bound(expand_row.begin(), expand_row.end(), r2);
            if(r1 < r2) {
                if(it2 != expand_row.begin()) {
                    it2--;
                    dr -= it2 - it1 + 1;
                    dr += MUL * (it2 - it1 + 1);
                } 
            } else {
                if(it1 != expand_row.begin()) {
                    it1--;
                    dr -= it1 - it2 + 1;
                    dr += MUL * (it1 - it2 + 1);
                }
            }

            it1 = std::upper_bound(expand_col.begin(), expand_col.end(), c1);
            it2 = std::upper_bound(expand_col.begin(), expand_col.end(), c2);

            if(c1 < c2) {
                if(it2 != expand_col.begin()) {
                    it2--;
                    dc -= it2 - it1 + 1;
                    dc += MUL * (it2 - it1 + 1);
                }
            } else {
                if(it1 != expand_col.begin()) {
                    it1--;
                    dc -= it1 - it2 + 1;
                    dc += MUL * (it1 - it2 + 1);
                }
            }

            ans += dr + dc;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string S;
    while(std::getline(std::cin, S)) {
        G.push_back(S);
    }

    run_case1();
    run_case2();
}
