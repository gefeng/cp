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

    auto is_digit = [](char c) {
        return c >= '0' && c <= '9';
    };

    auto is_delimiter = [](char c) {
        return c == ',' || c == ';';
    };
    
    int ans = 0;
    int64_t sum = 0; 
    while(std::getline(std::cin, S)) {
        int i = 0;
        int n = S.size();
        int id = 0;

        while(i < n) {
            if(!is_digit(S[i])) {
                i += 1;
            } else {
                while(i < n && S[i] != ':') {
                    id = id * 10 + S[i++] - '0';
                } 
                i += 1;
                break;
            }
        }
        
        std::array<int, 3> max_v = {};
        std::array<int, 3> cnt = {};
        int64_t power = 1;
        while(i < n) {
            if(S[i] == ' ' || is_delimiter(S[i])) {
                i += 1;
            }

            if(S[i] >= '0' && S[i] <= '9') {
                int j = i;
                int x = 0;
                while(i < n && is_digit(S[i])) {
                    x = x * 10 + S[i++] - '0';
                }
                
                i += 1;
                j = i;
                std::string color = "";
                while(i < n && !is_delimiter(S[i])) {
                    color.push_back(S[i++]);
                }

                if(color == "red") {
                    cnt[0] = x;
                } else if(color == "green") {
                    cnt[1] = x;
                } else {
                    cnt[2] = x;
                }
            }

            if(i == n || S[i] == ';') {
                for(int j = 0; j < 3; j++) {
                    max_v[j] = std::max(max_v[j], cnt[j]);
                    cnt[j] = 0;
                }
            }
        }

        for(int j = 0; j < 3; j++) {
            power *= max_v[j];
        } 

        ans += max_v[0] <= 12 && max_v[1] <= 13 && max_v[2] <= 14 ? id : 0;
        sum += power;
    }

    std::cout << ans << '\n' << sum << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
