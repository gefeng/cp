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

int decode(std::string& s, bool& enabled) {
    int n = s.size();
    int sum = 0;
    std::string prefix = "mul(";
    std::string s_do = "do()";
    std::string s_do_not = "don't()";
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

                if(enabled) {
                    sum += x * y;
                }
            }
        } else if(s[i] == 'd') {
            if(i + s_do.size() <= n && s.substr(i, s_do.size()) == s_do) {
                enabled = true;
                i += s_do.size() - 1;
            } else if(i + s_do_not.size() <= n && s.substr(i, s_do_not.size()) == s_do_not) {
                enabled = false;
                i += s_do_not.size() - 1;
            }
        }
    }
    
    return sum;
}

void run_case() {
    int ans = 0;
    bool enabled = true;
    for(std::string S; std::getline(std::cin, S); ) {
        ans += decode(S, enabled); 
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
