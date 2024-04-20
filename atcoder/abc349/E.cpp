#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = (int)3e5;

int hashify(std::vector<std::vector<int>>& g) {
    int h = 0;
    for(int i = 0; i < 3; i++) {
        int r = 0;
        for(int j = 0; j < 3; j++) {
            r <<= 2;
            r |= g[i][j];
        }
        h <<= 6;
        h |= r;
    }
    return h;
}

int check(std::vector<std::vector<int>>& g, std::vector<std::vector<int>>& G) {
    int cnt_r = 0;
    int cnt_b = 0;
    int64_t s1 = 0;
    int64_t s2 = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(g[i][j] == 1) {
                cnt_r += 1;
                s1 += G[i][j];
            } else if(g[i][j] == 2) {
                cnt_b += 1;
                s2 += G[i][j];
            }
        }
    }
    for(int i = 0; i < 3; i++) {
        if(g[i][0] && g[i][0] == g[i][1] && g[i][1] == g[i][2]) {
            return g[i][0]; 
        }
        if(g[0][i] && g[0][i] == g[1][i] && g[1][i] == g[2][i]) {
            return g[0][i];
        }
    }

    if(g[0][0] == g[1][1] && g[1][1] == g[2][2] && g[0][0]) {
        return g[0][0];
    }

    if(g[0][2] == g[1][1] && g[1][1] == g[2][0] && g[1][1]) {
        return g[1][1];
    }

    if(cnt_r + cnt_b == 9) {
        return s1 > s2 ? 1 : 2;
    }
    return 0;
}

int dfs(std::vector<std::vector<int>>& G, std::vector<std::vector<int>> g, std::vector<int>& dp) {
    int h = hashify(g);
    if(dp[h] != -1) {
        return dp[h];
    }

    int cnt_r = 0;
    int cnt_b = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(g[i][j] == 1) {
                cnt_r += 1;
            } else if(g[i][j] == 2) {
                cnt_b += 1;
            }
        }
    }

    int res = check(g, G);
    if(res == 1) {
        if(cnt_r == cnt_b) {
            return 1;      
        } else {
            return 0;
        }
    } else if(res == 2) {
        if(cnt_r == cnt_b) {
            return 0;
        } else {
            return 1;
        }
    }


    int win = 0;
    if(cnt_r == cnt_b) {
        // takahashi
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(g[i][j] == 0) {
                    g[i][j] = 1;
                    if(dfs(G, g, dp) == 0) {
                        win = 1;         
                    }
                    g[i][j] = 0;
                }
            }
        }
    } else {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(g[i][j] == 0) {
                    g[i][j] = 2;
                    if(dfs(G, g, dp) == 0) {
                        win = 1;
                    }
                    g[i][j] = 0;
                }
            }
        }
    }

    return dp[h] = win;
}

void run_case() {
    std::vector<std::vector<int>> G(3, std::vector<int>(3, 0));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cin >> G[i][j];
        }
    }

    std::vector<std::vector<int>> g(3, std::vector<int>(3, 0));

    std::vector<int> dp(MAX, -1);
    std::cout << (dfs(G, g, dp) ? "Takahashi" : "Aoki") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
