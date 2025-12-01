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

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

void run_case() {
    std::vector<std::string> G;
    std::string A = "";
    std::string M = ">v<^";
    
    bool reading_seq = false;
    for(std::string S; std::getline(std::cin, S); ) {
        if(S.empty()) {
            reading_seq = true;
            continue;
        }

        if(reading_seq) {
            A.append(S);
        } else {
            G.push_back(S);
        }
    }

    int n = G.size();
    int m = G[0].size();
    int q = A.size();
    int r = -1;
    int c = -1;
    std::map<int, std::set<int>> r_space;
    std::map<int, std::set<int>> c_space;   
    std::map<int, std::set<int>> r_box;
    std::map<int, std::set<int>> c_box;
    std::map<int, std::set<int>> r_wall;
    std::map<int, std::set<int>> c_wall;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(G[i][j] == '@') {
                r = i;
                c = j;
                G[i][j] = '.';
            } 
            if(G[i][j] == '.') {
                r_space[i].insert(j);
                c_space[j].insert(i);
            }
            if(G[i][j] == 'O') {
                r_box[i].insert(j);
                c_box[j].insert(i);
            }
            if(G[i][j] == '#') {
                r_wall[i].insert(j);
                c_wall[j].insert(i);
            }
        }
    }

    auto cover = [&](int r, int c) {
        r_space[r].erase(c);
        c_space[c].erase(r);
        r_box[r].insert(c);
        c_box[c].insert(r);
    };

    auto uncover = [&](int r, int c) {
        r_box[r].erase(c);
        c_box[c].erase(r);
        r_space[r].insert(c);
        c_space[c].insert(r);
    };

    auto block_row = [&](int r, int c, int nc) {
        if(nc > c) {
            auto it = r_wall[r].upper_bound(c);
            if(it == r_wall[r].end() || *it > nc) {
                return false;
            }
        } else {
            auto it = r_wall[r].upper_bound(c);
            if(it == r_wall[r].begin()) {
                return false;
            }
            it--;
            if(*it < nc) {
                return false;
            }
        }
        return true;
    };

    auto block_col = [&](int r, int c, int nr) {
        if(nr > r) {
            auto it = c_wall[c].upper_bound(r);
            if(it == c_wall[c].end() || *it > nr) {
                return false;
            }
        } else {
            auto it = c_wall[c].upper_bound(r);
            if(it == c_wall[c].begin()) {
                return false;
            }
            it--;
            if(*it < nr) {
                return false;
            }
        }
        return true;
    };
    
    for(int i = 0; i < q; i++) {
        int d = M.find(A[i]);
        int nr = r + DR[d];
        int nc = c + DC[d];

        if(r_space.find(nr) != r_space.end() && r_space[nr].find(nc) != r_space[nr].end()) {
            r = nr;
            c = nc;
            continue;
        }

        if(r_box.find(nr) == r_box.end() || r_box[nr].find(nc) == r_box[nr].end()) {
            continue;
        }
        
        if(A[i] == '<') {
            auto it = r_space[r].lower_bound(c);
            if(it == r_space[r].begin()) {
                continue;
            }
            it--;
            if(block_row(r, c, *it)) {
                continue;
            }
            cover(r, *it); 
            uncover(r, nc); 
        } else if(A[i] == '>') {
            auto it = r_space[r].upper_bound(c);
            if(it == r_space[r].end()) {
                continue;
            }
            if(block_row(r, c, *it)) {
                continue;
            }
            cover(r, *it);
            uncover(r, nc);
        } else if(A[i] == '^') {
            auto it = c_space[c].lower_bound(r);
            if(it == c_space[c].begin()) {
                continue;
            }
            it--;
            if(block_col(r, c, *it)) {
                continue;
            }
            cover(*it, c);
            uncover(nr, c);
        } else if(A[i] == 'v') {
            auto it = c_space[c].upper_bound(r);
            if(it == c_space[c].end()) {
                continue;
            }
            if(block_col(r, c, *it)) {
                continue;
            }
            cover(*it, c);
            uncover(nr, c);
        }

        r = nr;
        c = nc;
    }

    int64_t ans = 0;
    for(auto& [x, v] : r_box) {
        for(int y : v) {
            ans += x * 100 + y;
        } 
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
