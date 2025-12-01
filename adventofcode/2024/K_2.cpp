#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int MAX_T = 75;

int64_t next_int(std::string& s, int& p) {
    int64_t x = 0;
    int n = s.size();
    while(p < n && !std::isdigit(s[p])) {
        p += 1; 
    }

    if(p == n) {
        return -1;
    }

    while(p < n && std::isdigit(s[p])) {
        x = x * 10 + s[p++] - '0'; 
    }

    return x;
}

int count_digits(int64_t x) {
    int cnt = 0;
    while(x) {
        x /= 10;
        cnt += 1;
    }
    return cnt;
}

std::pair<int64_t, int64_t> split(int64_t x) {
    int64_t l = 0;
    int64_t r = 0;
    
    int cnt = count_digits(x);
    
    int64_t base = 1;
    for(int i = 0; i < cnt / 2; i++) {
        int d = x % 10;
        r += d * base; 
        base *= 10;
        x /= 10;
    }

    base = 1;
    for(int i = 0; i < cnt / 2; i++) {
        int d = x % 10;
        l += d * base;
        base *= 10;
        x /= 10;
    }

    return {l, r};
}

int64_t dfs(int64_t x, int t, std::map<std::pair<int64_t, int>, int64_t>& dp) {
    std::pair<int64_t, int> key = {x, t};
    if(t == MAX_T) {
        return 1; 
    }
    if(dp.find(key) != dp.end()) {
        return dp[key];
    }

    int64_t res = 0;
    if(x == 0) {
        res = dfs(1, t + 1, dp);
    } else {
        int cnt = count_digits(x);
        if(cnt % 2 == 0) {
            auto [l, r] = split(x);
            res = dfs(l, t + 1, dp) + dfs(r, t + 1, dp);
        } else {
            res = dfs(x * 2024, t + 1, dp);
        }
    }

    return dp[key] = res;
}

void run_case() {
    std::string S;
    std::getline(std::cin, S);

    int p = 0;
    std::vector<int64_t> a;
    while(true) {
        int64_t x = next_int(S, p);
        if(x == -1) {
            break;
        }
        a.push_back(x);
    }
    
    std::map<std::pair<int64_t, int>, int64_t> dp;
    int64_t ans = 0;
    for(int64_t x : a) {
        ans += dfs(x, 0, dp); 
    }
    std::cout << ans << '\n';

    // for(int64_t x : a) {
    //     std::vector<int64_t> b;
    //     b.push_back(x);
    //     for(int _{}; _ < MAX_T; _++) {
    //         std::vector<int64_t> nb;
    //         
    //         for(int64_t y : b) {
    //             if(y == 0) {
    //                 nb.push_back(1);
    //                 continue;
    //             } 
    //             
    //             int cnt = count_digits(y);
    //             if(cnt % 2 == 0) {
    //                 auto [l, r] = split(y);
    //                 nb.push_back(l);
    //                 nb.push_back(r);
    //             } else {
    //                 nb.push_back(y * 2024);
    //             }
    //         }
    //
    //         std::swap(b, nb);
    //         std::cout << b.size() << '\n';
    //         // for(int i = 0; i < a.size(); i++) {
    //         //     std::cout << a[i] << " \n"[i == a.size() - 1];
    //         // }
    //     }
    // }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
