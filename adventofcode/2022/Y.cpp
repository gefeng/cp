#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    LL sum = 0LL;
    std::string S;
    while(std::getline(std::cin, S)) {
        std::reverse(S.begin(), S.end());
        
        int sz = S.size();
        LL d = 1LL;
        LL x = 0LL;
        for(int i = 0; i < sz; i++) {
            if(S[i] == '-') {
                x -= d;
            } else if(S[i] == '=') {
                x -= 2LL * d;
            } else {
                x += d * (S[i] - '0');
            }
            d *= 5LL;
        }

        std::cout << x << '\n';
        sum += x;
    }

    std::string ans = "";
    LL x = sum;
    LL d = 1LL;
    int carry = 0;
    while(x) {
        int digit = (x % 5) + carry;

        if(digit > 2) {
            for(int i = 0; i < 3; i++) {
                LL y = d * digit + i * d;
                if(y % (d * 5LL) == 0) {
                    if(i == 0) {
                        ans.push_back('0');
                    } else if(i == 1) {
                        ans.push_back('-');
                    } else {
                        ans.push_back('=');
                    }

                    carry = y / (d * 5LL);
                    break;
                }
            } 
        } else {
            ans.push_back((char)(digit + '0'));
            carry = 0;
        }

        d *= 5LL;
        x /= 5LL;
    }

    if(carry) {
        ans.push_back((char)(carry + '0'));
    }

    std::reverse(ans.begin(), ans.end());
    std::cout << ans << '\n'; 
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
