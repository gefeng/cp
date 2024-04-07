#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

std::vector<int> manacher_odd(std::string s) {
    int n = s.size();
    s = "$" + s + "^";
    std::vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = std::max(0, std::min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return p;
}
 
std::vector<int> manacher(std::string s) {
    std::string t;
    for(auto c: s) {
        t += std::string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return std::vector<int>(begin(res) + 1, end(res) - 1);
}
 

void run_case() {
    std::string S;
    std::cin >> S;

    int n = S.size();
    
    auto is_pal = [&](int l, int r) {
        if(l < 0 || r < 0) {
            return false; 
        }

        while(l < r) {
            if(S[l] != S[r]) {
                return false;
            }
            l += 1;
            r -= 1;
        }
        return true;
    };

    auto all_same = [&](int l, int r) {
        for(int i = l; i <= r; i++) {
            if(S[i] != S[l]) {
                return false;
            }
        }
        return true;
    };

    if(!is_pal(0, n - 1)) {
        std::cout << "Yes" << '\n' << 1 << '\n';
        std::cout << S << '\n';
        return;
    }

    if(all_same(0, n - 1)) {
        std::cout << "No" << '\n';
        return;
    }

    std::vector<int> pal = manacher(S);
    for(int i = 0; i < n - 1; i++) {
        int l1 = 0;
        int r1 = i;
        int l2 = i + 1;
        int r2 = n - 1;
        int len1 = r1 - l1 + 1;
        int len2 = r2 - l2 + 1;
        int p1 = (2 * (l1 + r1 + 1) + 1) / 2;
        int p2 = (2 * (l2 + r2 + 1) + 1) / 2;
        int d1 = pal[p1] / 2 * 2 - (len1 % 2);
        int d2 = pal[p2] / 2 * 2 - (len2 % 2);
        
        if(d1 >= len1 || d2 >= len2) {
            continue; 
        }

        std::cout << "Yes" << '\n' << 2 << '\n';
        std::cout << S.substr(0, i + 1) << ' ' << S.substr(i + 1, n - i - 1) << '\n';
        return;
    } 

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
