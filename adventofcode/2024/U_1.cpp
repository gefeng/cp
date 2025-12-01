#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void dfs(std::map<char, std::pair<int, int>>& m, int x, int y, int tx, int ty, std::string& seq, std::vector<std::string>& all) {
    if(x == tx && y == ty) {
        all.push_back(seq + "A");
    }

    int dx = x <= tx ? 1 : -1;
    int dy = y <= ty ? 1 : -1;
    auto [bad_x, bad_y] = m['#'];
    if(x != tx) {
        if(x + dx != bad_x || y != bad_y) {
            seq.push_back(dx == 1 ? 'v' : '^');
            dfs(m, x + dx, y, tx, ty, seq, all); 
            seq.pop_back();
        }
    } 
    if(y != ty) {
        if(y + dy != bad_y || x != bad_x) {
            seq.push_back(dy == 1 ? '>' : '<');
            dfs(m, x, y + dy, tx, ty, seq, all);
            seq.pop_back();
        }
    }
}

void run_case() {
    std::vector<std::string> A;
    for(std::string S; std::getline(std::cin, S); ) {
        A.push_back(S); 
    }

    std::map<char, std::pair<int, int>> pm_1 = {
        {'#', {3, 0}},
        {'A', {3, 2}},
        {'0', {3, 1}},
        {'1', {2, 0}},
        {'2', {2, 1}},
        {'3', {2, 2}}, 
        {'4', {1, 0}},
        {'5', {1, 1}},
        {'6', {1, 2}},
        {'7', {0, 0}},
        {'8', {0, 1}},
        {'9', {0, 2}}
    };
    std::map<char, std::pair<int, int>> pm_2 = {
        {'#', {0, 0}},
        {'A', {0, 2}},
        {'^', {0, 1}},
        {'<', {1, 0}},
        {'v', {1, 1}},
        {'>', {1, 2}}
    };
    
    auto gen = [&](std::string& s, int keyboard) {
        std::string seq = "";
        int n = s.size();

        std::map<char, std::pair<int, int>> m;
        if(keyboard == 1) {
            m = pm_1; 
        } else {
            m = pm_2;
        }

        std::vector<std::string> now;
        now.push_back("");
        auto [x, y] = m['A'];
        for(int i = 0; i < n; i++) {
            auto [nx, ny] = m[s[i]];
            std::vector<std::string> nxt;
            std::vector<std::string> a;
            std::string seq = "";
            dfs(m, x, y, nx, ny, seq, a);
            
            for(std::string& t : now) {
                for(std::string& tt : a) {
                    nxt.push_back(t + tt);
                }
            }

            x = nx;
            y = ny;

            std::swap(now, nxt);
        }

        return now;
    };

    int64_t ans = 0;
    for(std::string& s : A) {
        std::vector<std::string> now = gen(s, 1);

        // for(std::string& t : all) {
        //     std::cout << t << '\n';
        // }
        
        for(int i = 0; i < 2; i++) {
            std::vector<std::string> nxt;
            for(std::string& t : now) {
                std::vector<std::string> all = gen(t, 2);
                for(std::string& x : all) {
                    nxt.push_back(x);
                } 
            }
            std::swap(now, nxt);
        }

        int min_len = int(1e9);
        for(std::string& t : now) {
            min_len = std::min(min_len, int(t.size()));
        }
        std::cout << min_len << '\n';
        ans += int64_t(stoi(s.substr(0, 3))) * min_len; 
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
