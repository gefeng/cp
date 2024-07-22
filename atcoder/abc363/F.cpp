#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

bool is_pal(std::string& s) {
    int l = 0;
    int r = s.size() - 1;
    while(l <= r) {
        if(s[l] != s[r] || s[l] == '0') {
            return false;
        }
        l += 1;
        r -= 1;
    }
    return true;
};

std::string dfs(int64_t N, std::map<int64_t, std::string>& dp) {
    std::string s = std::to_string(N);
    if(is_pal(s)) {
        return dp[N] = "1*" + s + "*1";
    }
    
    if(dp.find(N) != dp.end()) {
        return dp[N];
    }

    std::string res = "";
    //std::cout << N << '\n';
    for(int64_t f = 2; f * f <= N; f++) {
        if(N % f == 0) {
            std::array<int64_t, 2> a = {f, N / f};

            for(int64_t x : a) {
                std::string l = std::to_string(x);
                std::string r = l;
                std::reverse(r.begin(), r.end());
                std::string t = l + r;
                int64_t rx = std::stoll(r);
                if(is_pal(t) && N % (x * rx) == 0) {
                    std::string ret = dfs(N / x / rx, dp);
                    if(!ret.empty()) {
                        res = l + "*" + ret + "*" + r;
                        return dp[N] = res;
                    }
                }
            }
        }
    }

    return dp[N] = res;
}

void run_case() {
    int64_t N;
    std::cin >> N;

    std::map<int64_t, std::string> dp;

    std::string ans = dfs(N, dp);
    
    std::cout << (ans.empty() ? "-1" : ans) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
