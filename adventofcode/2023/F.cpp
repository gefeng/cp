#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

std::vector<int> T;
std::vector<int> D;

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

void run_case1() {
    int n = T.size();
    
    int64_t ans = 1;
    for(int i = 0; i < n; i++) {
        int64_t cnt_win = 0;
        
        for(int64_t hold = 1; hold < T[i]; hold += 1) {
            int64_t speed = hold;
            int64_t time = T[i] - hold;
            if(time * speed > D[i]) {
                cnt_win += 1; 
            }
        }

        ans *= cnt_win;
    }

    std::cout << ans << '\n';
}

void run_case2() {
    int n = T.size();

    int64_t ans = 0;

    std::vector<int64_t> p10(18, 1);
    for(int i = 1; i < 18; i++) {
        p10[i] = p10[i - 1] * 10;
    }
    
    int64_t t = 0;
    int64_t d = 0;
    int len_t = 0;
    int len_d = 0;
    for(int i = n - 1; i >= 0; i--) {
        t += T[i] * p10[len_t];
        d += D[i] * p10[len_d];
        int x = T[i];
        while(x) {
            x /= 10;
            len_t += 1;
        }

        x = D[i];
        while(x) {
            x /= 10;
            len_d += 1;
        }
    }

    for(int64_t hold = 1; hold < t; hold += 1) {
        int64_t speed = hold;
        int64_t time = t - hold;
        if(time * speed > d) {
            ans += 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::string S;
    while(std::getline(std::cin, S)) {
        int n = S.size();
        for(int i = 0; i < n; ) {
            if(is_digit(S[i])) {
                int x = 0;
                while(i < n && is_digit(S[i])) {
                    x = x * 10 + S[i++] - '0';
                }
                if(S[0] == 'T') {
                    T.push_back(x);
                } else {
                    D.push_back(x);
                }
            } else {
                i += 1;
            }
        }
    }
    
    run_case1();
    run_case2();
}
