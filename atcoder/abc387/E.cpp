#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;
    std::cin >> S;

    int n = S.size();
    
    if(n < 4) {
        int l = stoi(S);
        int r = l * 2;
        for(int x = l; x < r; x++) {
            int a = x;
            int b = x + 1;
            int sa = 0;
            int sb = 0;
            while(a) {
                sa += a % 10;
                a /= 10;
            }
            while(b) {
                sb += b % 10;
                b /= 10;
            }

            if(x % sa == 0 && (x + 1) % sb == 0) {
                std::cout << x << '\n';
                return;
            }
        }
        std::cout << -1 << '\n';
        return;
    }

    std::string l = S;
    std::string r = "";
    int c = 0;
    for(int i = n - 1; i >= 0; i--) {
        int d = (S[i] - '0') * 2 + c;
        r.push_back(char(d % 10 + '0'));
        c = d / 10;
    }
    if(c) {
        r.push_back('1');
    }
    std::reverse(r.begin(), r.end());
    int m = r.size();

    std::array<int, 7> a = {16, 24, 32, 40, 120, 200, 1000}; 
    std::array<int, 7> b = {17, 25, 33, 41, 121, 201, 1001};

    auto cmp = [](std::string& s, std::string& t) {
        if(s.size() == t.size()) {
            if(s == t) {
                return 0;
            }
            return s < t ? -1 : 1;
        }
        return s.size() < t.size() ? -1 : 1;
    };
    
    for(int i = 1; i <= 7; i++) {
        std::string prefix = std::to_string(i);
        std::string suffix = std::to_string(a[i - 1]);
        
        for(int size : {n, m}) {
            if(prefix.size() + suffix.size() <= size) {
                int zero = size - prefix.size() - suffix.size();
                std::string x = prefix;
                std::string y = prefix;
                for(int j = 0; j < zero; j++) {
                    x.push_back('0');
                    y.push_back('0');
                }
                x.append(suffix);
                y.append(std::to_string(b[i - 1]));
                
                if(cmp(x, l) >= 0 && cmp(x, r) <= 0 && cmp(y, l) >= 0 && cmp(y, r) <= 0) {
                    std::cout << x << '\n';
                    return;
                }
            } 
        }
    }

    std::cout << -1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
