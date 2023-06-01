#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <map>

using LL = long long;

constexpr int INF = 2e9;
constexpr int MAX_T = 26;

LL dfs1(std::vector<std::vector<int>>& g, std::vector<int>& a, std::vector<int>& use, 
        int m, int v, int t, std::vector<std::vector<std::vector<LL>>>& dp) {
    if(t >= MAX_T) {
        return 0LL;
    } 
    if(m == 0) {
        return 0LL;
    }

    if(dp[v][t][m] != -1LL) {
        return dp[v][t][m];
    }

    LL res = 0LL;
    for(int nv : g[v]) {
        if(nv == v) {
            continue;
        }

        res = std::max(res, dfs1(g, a, use, m, nv, t + 1, dp));

        if(use[v] != -1 && m & (1 << use[v])) {
            res = std::max(res, dfs1(g, a, use, m ^ (1 << use[v]), nv, t + 2, dp) + 1LL * a[v] * (MAX_T - t - 1));
        }
    }

    return dp[v][t][m] = res;
}

LL dfs2(std::vector<std::vector<int>>& g, std::vector<int>& a, std::vector<int>& use, 
        int m, int v1, int v2, int t, std::vector<std::vector<std::vector<std::vector<LL>>>>& dp) {
    if(t >= MAX_T) {
        return 0LL;
    } 
    if(m == 0) {
        return 0LL;
    }

    if(dp[v1][v2][t][m] != -1LL) {
        return dp[v1][v2][t][m];
    }

    bool open1 = use[v1] != -1 && (m & (1 << use[v1]));
    bool open2 = use[v2] != -1 && (m & (1 << use[v2]));
    LL p1 = 1LL * a[v1] * (MAX_T - t - 1);
    LL p2 = 1LL * a[v2] * (MAX_T - t - 1); 
    LL res = 0LL;

    for(int nv1 : g[v1]) {
        if(nv1 != v1) {
            for(int nv2 : g[v2]) {
                if(nv2 != v2) {
                    res = std::max(res, dfs2(g, a, use, m, nv1, nv2, t + 1, dp));
                }
            }
        }
    }

    if(open1) {
        for(int nv2 : g[v2]) {
            if(nv2 != v2) {
                res = std::max(res, dfs2(g, a, use, m ^ (1 << use[v1]), v1, nv2, t + 1, dp) + p1);
            }
        }
    } 

    if(open2) {
        for(int nv1 : g[v1]) {
            if(nv1 != v1) {
                res = std::max(res, dfs2(g, a, use, m ^ (1 << use[v2]), nv1, v2, t + 1, dp) + p2);
            }
        }
    }

    if(open1 && open2 && v1 != v2) {
        int nm = m;
        nm ^= 1 << use[v1];
        nm ^= 1 << use[v2];
        res = std::max(res, dfs2(g, a, use, nm, v1, v2, t + 1, dp) + p1 + p2);
    }

    return dp[v1][v2][t][m] = res;
}

struct valve {
    std::string name;
    std::vector<std::string> to;
    int rate;
    valve(std::string _name, int _rate, std::vector<std::string> _to) : name(_name), rate(_rate), to(_to) {}
};

void run_case() {
    auto is_upper = [](char c) {
        return c >= 'A' && c <= 'Z';
    };

    auto is_digit = [](char c) {
        return c >= '0' && c <= '9';     
    };

    std::string S;
    std::vector<valve> A;
    while(std::getline(std::cin, S)) {
        int sz = S.size();
        std::vector<std::string> v;
        int rate = 0;
        for(int i = 0; i < sz; ) {
            if(is_upper(S[i]) && is_upper(S[i + 1])) {
                v.push_back(S.substr(i, 2)); 
                i += 2;
            } else if(is_digit(S[i])) {
                while(i < sz && is_digit(S[i])) {
                    rate = rate * 10 + S[i] - '0';
                    i += 1;
                }
            } else {
                i += 1;
            }
        } 

        valve x(v[0], rate, std::vector<std::string>(v.begin() + 1, v.end()));
        A.push_back(x);
    }   
    
    std::sort(A.begin(), A.end(), [](auto& a, auto& b) { 
            return a.name < b.name; });

    std::map<std::string, int> to_v;
    for(auto& x : A) {
        to_v[x.name] = to_v.size();
    }

    int n = A.size();
    int cnt_use = 0;
    std::vector<std::vector<int>> g(n);
    std::vector<int> a(n, 0);
    std::vector<int> use(n, -1);
    for(auto& x : A) {
        int from = to_v[x.name];
        for(auto& y : x.to) {
            int to = to_v[y];
            g[from].push_back(to);
            g[to].push_back(from);
        }

        a[from] = x.rate;
        if(x.rate) {
            use[from] = cnt_use++;
        }
    }

    //std::vector<std::vector<std::vector<LL>>> dp(n, std::vector<std::vector<LL>>(MAX_T, std::vector<LL>(1 << cnt_use, -1LL)));
    //std::cout << dfs1(g, a, use, (1 << cnt_use) - 1, 0, 0, dp) << '\n';

    std::vector<std::vector<std::vector<std::vector<LL>>>> dp(n, 
            std::vector<std::vector<std::vector<LL>>>(n, std::vector<std::vector<LL>>(MAX_T + 1, std::vector<LL>(1 << cnt_use, -1))));
    std::cout << dfs2(g, a, use, (1 << cnt_use) - 1, 0, 0, 0, dp) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
