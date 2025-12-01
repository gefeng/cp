#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int64_t INF = int64_t(2e18);
constexpr int MAX_LV = 25;

std::map<std::pair<std::string, int>, int64_t> dp;

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

std::vector<std::string> gen(char from, char to) {
    std::vector<std::string> res;
    if(from == '^') {
        if(to == 'A') {
            res.push_back(">A"); 
        } else if(to == '>') {
            res.push_back(">vA");
            res.push_back("v>A");
        } else if(to == 'v') {
            res.push_back("vA");
        } else if(to == '<') {
            res.push_back("v<A");
        } else {
            res.push_back("A");
        }
    } else if(from == 'A') {
        if(to == '^') {
            res.push_back("<A");
        } else if(to == '>') {
            res.push_back("vA");
        } else if(to == 'v') {
            res.push_back("v<A");
            res.push_back("<vA");
        } else if(to == '<') {
            res.push_back("<v<A");
            res.push_back("v<<A");
        } else {
            res.push_back("A");
        }
    } else if(from == '<') {
        if(to == 'v') {
            res.push_back(">A");
        } else if(to == '>') {
            res.push_back(">>A");
        } else if(to == '^') {
            res.push_back(">^A");
        } else if(to == 'A') {
            res.push_back(">>^A");
            res.push_back(">^>A");
        } else {
            res.push_back("A");
        }
    } else if(from == 'v') {
        if(to == '<') {
            res.push_back("<A");
        } else if(to == '>') {
            res.push_back(">A");
        } else if(to == '^') {
            res.push_back("^A");
        } else if(to == 'A') {
            res.push_back("^>A");
            res.push_back(">^A");
        } else {
            res.push_back("A");
        }
    } else if(from == '>') {
        if(to == 'v') {
            res.push_back("<A");
        } else if(to == '<') {
            res.push_back("<<A");
        } else if(to == 'A') {
            res.push_back("^A");
        } else if(to == '^') {
            res.push_back("^<A");
            res.push_back("<^A");
        } else {
            res.push_back("A");
        }
    }
    return res;
}

int64_t dfs_2(int t, char from, std::string& s, int lv) {
    if(lv == t) {
        return s.size();
    }
    
    std::pair<std::string, int> key = {s, lv};
    if(dp.find(key) != dp.end()) {
        return dp[key];
    }

    int64_t res = 0;

    int n = s.size();
    char last = from;
    for(int i = 0; i < n; i++) {
        std::vector<std::string> a;
        if(i == 0) {
            a = gen(from, s[i]);
        } else {
            a = gen(s[i - 1] , s[i]);
        }
        
        int64_t min_len = INF;
        char n_last = last;
        for(std::string& x : a) {
            int64_t len = dfs_2(t, last, x, lv + 1);
            if(len < min_len) {
                min_len = len; 
                n_last = x.back();
            }
        }
        last = n_last;
        res += min_len;
    }
    
    dp[key] = res;
    return res;
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

        int64_t min_v = INF;
        for(std::string& t : now) {
            min_v = std::min(min_v, dfs_2(MAX_LV, 'A', t, 0));
        }
        
        ans += int64_t(stoi(s.substr(0, 3))) * min_v;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
