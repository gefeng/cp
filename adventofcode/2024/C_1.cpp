#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int next_int(std::string& s, int& p) {
    int x = 0;
    int n = s.size();
    if(s[p] < '0' || s[p] > '9') {
        p -= 1;
        return -1;
    } 

    int cnt = 0;
    while(p < n && s[p] >= '0' && s[p] <= '9') {
        x = x * 10 + s[p] - '0';
        p += 1; 
        cnt += 1;
    }

    if(cnt > 3) {
        return -1;
    }
    
    return x;
}

int decode(std::string& s) {
    int n = s.size();
    int sum = 0;
    std::string prefix = "mul(";
    for(int i = 0; i < n; i++) {
        if(s[i] == 'm') {
            if(i + prefix.size() <= n && s.substr(i, prefix.size()) == prefix) {
                i += prefix.size();
                
                int x = next_int(s, i);
                if(x == -1) {
                    continue;
                }

                if(s[i] != ',') {
                    i -= 1;
                    continue;
                }
                i += 1;

                int y = next_int(s, i);
                if(y == -1) {
                    continue;
                }

                if(s[i] != ')') {
                    i -= 1;
                    continue;
                }

                sum += x * y;
            }
        }
    }
    
    return sum;
}

void run_case() {
    int ans = 0;
    for(std::string S; std::getline(std::cin, S); ) {
        ans += decode(S); 
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
