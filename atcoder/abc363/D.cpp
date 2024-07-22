#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N;
    std::cin >> N;

    int len = 0;
    int64_t x = 1;
    std::string ans = "";
    while(N) {
        if(len == 0) {
            if(N <= 10) {
                ans = std::to_string(N - 1);
                break;
            } 
            N -= 10;
        } else {
            int64_t tot = x - x / 10;
            if(N <= tot) {
                ans = std::to_string(x / 10 + N - 1);
                std::string s(ans);
                std::reverse(s.begin(), s.end());
                ans += s;
                break; 
            } 
            N -= tot;

            tot *= 10;    
            if(N <= tot) {
                ans = std::to_string(x + N - 1);
                std::string s(ans.substr(0, ans.size() - 1)); 
                std::reverse(s.begin(), s.end());
                ans += s;
                break;
            }
            N -= tot;
        }
        len += 1;
        x *= 10;
    } 

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
