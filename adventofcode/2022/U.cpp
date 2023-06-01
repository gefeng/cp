#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using LL = long long;

constexpr LL INF = (LL)2e18;
const std::string YOU = "humn";
const std::string ROOT = "root";

LL dfs1(std::map<std::string, std::vector<std::string>>& g, std::map<std::string, LL>& mv, std::map<std::string, char>& mo, std::string v) {
    if(g.find(v) == g.end()) {
        if(v == YOU) {
            return INF;
        }
        return mv[v];
    }

    LL x = dfs1(g, mv, mo, g[v][0]);
    LL y = dfs1(g, mv, mo, g[v][1]);

    if(x != INF && y != INF) {
        char op = mo[v];
    
        LL res = 000000000;
        if(op == '+') {
            res = x + y;
        } else if(op == '-') {
            res = x - y;
        } else if(op == '*') {
            res = x * y;
        } else {
            res = x / y;
        }

        mv[v] = res;

        return res;
    } else {
        return INF;
    }
}

void dfs2(std::map<std::string, std::vector<std::string>>& g, std::map<std::string, LL>& mv, std::map<std::string, char>& mo, std::string v, LL t) {
    if(g.find(v) == g.end()) {
        mv[v] = t;
        return;
    }

    std::string x;
    std::string y;

    for(std::string nei : g[v]) {
        if(mv.find(nei) == mv.end() || nei == YOU) {
            x = nei; 
        } else {
            y = nei;
        }
    }

    if(v != ROOT) {
        char op = mo[v];
        if(op == '+') {
            t = t - mv[y]; 
        } else if(op == '*') {
            t = t / mv[y]; 
        } else if(op == '-') {
            if(y == g[v][1]) {
                t = t + mv[y];
            } else {
                t = mv[y] - t;
            }
        } else {
            if(y == g[v][1]) {
                t = t * mv[y]; 
            } else {
                t = mv[y] / t;
            }
        }
    }

    dfs2(g, mv, mo, x, t);
}

void run_case() {
    std::map<std::string, std::vector<std::string>> g;
    std::map<std::string, LL> mv;
    std::map<std::string, char> mo;

    auto is_digit = [](char c) {
        return c >= '0' && c <= '9'; 
    };

    std::string S;
    while(std::getline(std::cin, S)) {
        int n = S.size();
        int p = S.find(":");
        
        std::string v = S.substr(0, p);

        if(is_digit(S[p + 2])) {
            int x = 0;
            for(int i = p + 2; i < n; i++) {
                x = x * 10 + S[i] - '0';
            }             
            mv[v] = x;
        } else {
            p += 2;
            std::string c1 = "";
            while(p < n && S[p] != ' ') {
                c1.push_back(S[p++]);
            }

            p += 1;
            mo[v] = S[p++];
            p += 1;
            
            std::string c2 = "";
            while(p < n) {
                c2.push_back(S[p++]);
            }

            g[v].push_back(c1);
            g[v].push_back(c2);
        }
    }

    dfs1(g, mv, mo, ROOT);
    
    LL t = mv.find(g[ROOT][0]) == mv.end() ? mv[g[ROOT][1]] : mv[g[ROOT][0]];

    dfs2(g, mv, mo, ROOT, t);

    std::cout << mv[YOU] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
