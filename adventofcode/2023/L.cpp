#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

std::vector<std::string> A;
std::vector<std::vector<int>> B;

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int64_t dfs(std::string& s, std::vector<int>& a, int p1, int p2, std::vector<std::vector<int64_t>>& dp) {
    int64_t res = 0;
    int n = s.size();
    int m = a.size();
    if(p1 == n && p2 == m) {
        return 1;
    }
    if(p1 == n) {
        return 0;    
    }
    if(p2 == m) {
        for(int i = p1; i < n; i++) {
            if(s[i] == '#') {
                return 0;
            }
        }
        return 1;
    }

    if(dp[p1][p2] != -1) {
        return dp[p1][p2];
    }

    if(s[p1] != '#') {
        res += dfs(s, a, p1 + 1, p2, dp);
    }

    if(s[p1] != '.') {
        int len = a[p2];
        if(p1 + len <= n) {
            bool ok = true;
            for(int i = p1; i < p1 + len; i++) {
                if(s[i] == '.') {
                    ok = false; 
                    break;
                }
            }

            if(p1 + len < n && s[p1 + len] == '#') {
                ok = false;
            }

            if(ok) {
                res += dfs(s, a, std::min(n, p1 + len + 1), p2 + 1, dp);
            }
        }
    }

    return dp[p1][p2] = res;
}

void run_case1() {
    int n = A.size();
    int64_t ans = 0;
    for(int i = 0; i < n; i++) {
        std::vector<std::vector<int64_t>> dp(A[i].size(), std::vector<int64_t>(B[i].size(), -1));
        ans += dfs(A[i], B[i], 0, 0, dp);
    }

    std::cout << ans << '\n';
}

void run_case2() {
    int n = A.size();
    int64_t ans = 0;
    for(int i = 0; i < n; i++) {
        std::string s = "";
        std::vector<int> a;
        for(int j = 0; j < 5; j++) {
            s.append(A[i]);
            if(j < 4) {
                s.push_back('?');
            }

            int size = B[i].size();
            for(int k = 0; k < size; k++) {
                a.push_back(B[i][k]);
            }
        }

        std::vector<std::vector<int64_t>> dp(s.size(), std::vector<int64_t>(a.size(), -1));
        ans += dfs(s, a, 0, 0, dp);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
   
    std::string S;
    while(std::getline(std::cin, S)) {
        int p = S.find(' ');
        int n = S.size();
        A.push_back(S.substr(0, p));
        
        p += 1;
        B.emplace_back();
        while(p < n) {
            if(is_digit(S[p])) {
                int x = 0;
                while(p < n && is_digit(S[p])) {
                    x = x * 10 + S[p++] - '0';
                }
                B.back().push_back(x); 
            } else {
                p += 1;
            }
        }
    }

    run_case1();
    run_case2();
}
