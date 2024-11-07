#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int H, M;
    std::cin >> H >> M;
    
    std::string S;
    std::cin >> S;

    auto to_min = [&](std::string s) {
        return ((s[0] - '0') * 10 + (s[1] - '0')) * M + (s[3] - '0') * 10 + (s[4] - '0');
    };

    auto to_time = [&](int t) {
        std::string s = "";
        int h = t / M;
        int m = t % M;
        s.push_back(h < 10 ? '0' : char(h / 10 + '0'));
        s.push_back(char(h % 10 + '0'));
        s.push_back(':');
        s.push_back(m < 10 ? '0' : char(m / 10 + '0'));
        s.push_back(char(m % 10 + '0'));
        return s;
    };

    auto is_good = [&](int t) {
        std::string s = to_time(t);
        for(int i = 0; i < 5; i++) {
            if(i == 2) {
                continue;
            }
            if(s[i] == '3' || s[i] == '4' || s[i] == '6' || s[i] == '7' || s[i] == '9') {
                return false;
            }
        }
        
        std::reverse(s.begin(), s.end());
        
        for(int i = 0; i < 5; i++) {
            if(s[i] == '2') {
                s[i] = '5';
            } else if(s[i] == '5') {
                s[i] = '2';
            } 
        }

        int h = (s[0] - '0') * 10 + (s[1] - '0');
        int m = (s[3] - '0') * 10 + (s[4] - '0');

        return h < H && m < M;
    };

    int n = H * M;
    for(int i = 0, t = to_min(S); i < n; i++, t = (t + 1) % n) {
        if(is_good(t)) {
            std::cout << to_time(t) << '\n';
            return;
        }
    }
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
