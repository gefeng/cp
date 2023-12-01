#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case1() {
    std::string S;
    
    int64_t sum = 0;
    while(std::getline(std::cin, S)) {
        int n = S.size();
        int first = -1;
        int last = -1;
        for(int i = 0; i < n; i++) {
            if(S[i] >= '0' && S[i] <= '9') {
                if(first == -1) {
                    first = S[i] - '0';
                } 
                last = S[i] - '0';
            }
        }
        sum += first * 10 + last;
    }

    std::cout << sum << '\n';
}

void run_case2() {
    std::string S;

    std::vector<std::pair<std::string, int>> e = {{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, 
        {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
    auto is_digit = [&](std::string& s, int i) {
        int res = -1;
        for(auto& [t, v] : e) {
            if(s.size() - i >= t.size() && s.substr(i, t.size()) == t) {
                res = v; 
                break;
            }
        } 
        return res;
    };
    
    int64_t sum = 0;
    while(std::getline(std::cin, S)) {
        int n = S.size(); 
        int first = -1;
        int last = -1;
        for(int i = 0; i < n; i++) {
            if(S[i] >= '0' && S[i] <= '9') {
                if(first == -1) {
                    first = S[i] - '0';
                }
                last = S[i] - '0';
            } else {
                int res = is_digit(S, i);
                if(res != -1) {
                    if(first == -1) {
                        first = res;
                    }
                    last = res;
                }
            }
        }

        sum += first * 10 + last;
    }

    std::cout << sum << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    //run_case1();
    run_case2();
}
