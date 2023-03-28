#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

LL dfs(std::vector<int>& digits, std::vector<int>& S, int s_pos, int cur, int bounded, int zero, std::vector<std::vector<std::vector<LL>>>& dp) {
    int n = digits.size();
    int m = S.size();

    if(cur == n) {
        return 1LL;
    }

    if(dp[bounded][zero][cur] != -1LL) {
        return dp[bounded][zero][cur];
    }

    LL res = 0LL;
    if(cur >= s_pos && cur < s_pos + m) {
        if(!zero || S[0] != 0) {
            int d = S[cur - s_pos];
            if(bounded) {
                if(d == digits[cur]) {
                    res += dfs(digits, S, s_pos, cur + 1, bounded, 0, dp);
                } else if(d < digits[cur]) {
                    res += dfs(digits, S, s_pos, cur + 1, 0, 0, dp);
                }
            } else {
                res += dfs(digits, S, s_pos, cur + 1, 0, 0, dp);
            }
        }
    } else {
        if(bounded) {
            if(cur == 0) {
                res += dfs(digits, S, s_pos, cur + 1, 1, 0, dp);  // pick the same;
                res += dfs(digits, S, s_pos, cur + 1, 0, 1, dp);  // pick zero
                res += dfs(digits, S, s_pos, cur + 1, 0, 0, dp) * (digits[cur] - 1); // pick non-zero
            } else {
                res += dfs(digits, S, s_pos, cur + 1, 1, zero, dp);  // pick the same;
                if(digits[cur]) {
                    res += dfs(digits, S, s_pos, cur + 1, 0, zero, dp) * digits[cur];
                }
            }
        } else {
            if(zero) {
                res += dfs(digits, S, s_pos, cur + 1, 0, zero, dp);
                res += dfs(digits, S, s_pos, cur + 1, 0, 0, dp) * 9LL;
            } else {
                res += dfs(digits, S, s_pos, cur + 1, 0, zero, dp) * 10LL;
            }
        }
    }

    return dp[bounded][zero][cur] = res;
}

void run_case() {
    std::string S;
    std::cin >> S;

    LL L, R;
    std::cin >> L >> R;

    std::vector<int> s;
    std::vector<int> digits_r;
    std::vector<int> digits_l;

    for(char c : S) {
        s.push_back(c - '0');
    } 

    LL x = R;
    while(x) {
        digits_r.push_back(x % 10LL);
        x /= 10LL;
    }
    
    x = L - 1;
    while(x) {
        digits_l.push_back(x % 10LL);
        x /= 10LL;
    }

    std::reverse(digits_r.begin(), digits_r.end());
    std::reverse(digits_l.begin(), digits_l.end());

    LL ans = 0LL;
    int st = s[0] == 0 ? 1 : 0;

    for(int i = st; i < 17; i++) {
        if(i + s.size() <= digits_r.size()) {
            std::vector<std::vector<std::vector<LL>>> dp(2, std::vector<std::vector<LL>>(2, std::vector<LL>(digits_r.size(), -1LL)));
            ans += dfs(digits_r, s, i, 0, 1, 1, dp);
        }
    }

    for(int i = st; i < 17; i++) {
        if(i + s.size() <= digits_l.size()) {
            std::vector<std::vector<std::vector<LL>>> dp(2, std::vector<std::vector<LL>>(2, std::vector<LL>(digits_l.size(), -1LL)));
            ans -= dfs(digits_l, s, i, 0, 1, 1, dp);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    
    while(T--) {
        run_case();
    }
}
