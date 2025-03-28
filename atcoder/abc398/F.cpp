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

    std::vector<int> pal = manacher(S);

    auto query = [&](int l, int r) {
        int len = r - l + 1;
        int p = (2 * (l + r + 1) + 1) / 2;
        int d = pal[p] / 2 * 2 - (len % 2);
        return d >= len;
    };
    
    int min_len = n * 2;
    int p = -1;
    std::string ans = "";
    for(int l = n - 1; l >= 0; l--) {
        if(query(l, n - 1)) {
            int len = n - l + l * 2;
            if(len < min_len) {
                min_len = len;
                p = l;   
            } 
        }
    }

    std::string prefix = S.substr(0, p);
    ans += prefix;
    ans += S.substr(p, n - p);
    std::reverse(prefix.begin(), prefix.end());
    ans += prefix;

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
