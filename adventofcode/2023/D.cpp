#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

std::vector<std::string> A;

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

void run_case1() {
    int64_t ans = 0;

    for(std::string s : A) {
        int n = s.size();
        int id = -1;
        bool seen_delimiter = false;
        std::set<int> winning;
        std::vector<int> have;
        
        for(int i = 0; i < n; i++) {
            if(is_digit(s[i])) {
                int x = 0;
                while(i < n && is_digit(s[i])) {
                    x = x * 10 + s[i++] - '0';
                }
                if(id == -1) {
                    id = x;
                } else {
                    if(!seen_delimiter) {
                        winning.insert(x);
                    } else {
                        have.push_back(x);
                    }
                }
            } else if(s[i] == '|') {
                seen_delimiter = true; 
            }
        }

        int64_t score = 0;
        for(int x : have) {
            if(winning.find(x) != winning.end()) {
                score = score == 0 ? 1 : score * 2;
            }
        }

        ans += score;
    }

    std::cout << ans << '\n';
}

void run_case2() {
    int64_t ans = 0;
    int n = A.size(); 

    std::vector<int64_t> save(n + 1, 0);
    std::vector<int64_t> res(n + 1, 1);

    for(std::string s : A) {
        int size = s.size();
        int id = -1;
        bool seen_delimiter = false;
        std::set<int> winning;
        std::vector<int> have;
        
        for(int i = 0; i < size; i++) {
            if(is_digit(s[i])) {
                int x = 0;
                while(i < size && is_digit(s[i])) {
                    x = x * 10 + s[i++] - '0';
                }
                if(id == -1) {
                    id = x;
                } else {
                    if(!seen_delimiter) {
                        winning.insert(x);
                    } else {
                        have.push_back(x);
                    }
                }
            } else if(s[i] == '|') {
                seen_delimiter = true; 
            }
        }

        int cnt_win = 0;
        for(int x : have) {
            if(winning.find(x) != winning.end()) {
                cnt_win += 1;
            }
        }

        save[id] = cnt_win;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= save[i]; j++) {
            if(i + j <= n) {
                res[i + j] += res[i]; 
            } 
        }
        ans += res[i];
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    std::string S;
    std::cin >> S;

    while(std::getline(std::cin, S)) {
        A.push_back(S); 
    }

    run_case1();
    run_case2();
}
