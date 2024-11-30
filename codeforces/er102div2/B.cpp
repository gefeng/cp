#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void run_case() {
    std::string S;
    std::string T;

    std::cin >> S >> T;

    int n = S.size();
    int m = T.size();
    
    if(n > m) {
        std::swap(S, T);
        std::swap(n, m);
    }

    auto is_repeat = [](std::string& s, std::string& t) {
        std::string x = "";
        int n = s.size() / t.size();
        for(int i = 0; i < n; i++) {
            x.append(t);
        }
        return s == x;
    };

    for(int i = 1; i <= n; i++) {
        if(m % i == 0 && n % i == 0) {
            std::string s = S.substr(0, i);
            if(is_repeat(S, s) && is_repeat(T, s)) {
                int copy = lcm(m / i, n / i); 
                std::string ans = "";
                while(copy--) {
                    ans.append(s);
                }
                std::cout << ans << '\n';
                return;
            }
        }
    }

    std::cout << -1 << '\n';
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
