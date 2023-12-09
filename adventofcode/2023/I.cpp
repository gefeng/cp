#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

std::vector<std::vector<int64_t>> A;

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

void run_case1() {
    int n = A.size();
    int64_t ans = 0;
    for(int i = 0; i < n; i++) {
        std::vector<int64_t> cur(A[i]);
        std::vector<int64_t> last;
        while(true) {
            last.push_back(cur.back());

            int size = cur.size();
            if(size == 1) {
                break;
            }
            
            std::vector<int64_t> nxt;
            bool equal = true;
            for(int j = 1; j < size; j++) {
                nxt.push_back(cur[j] - cur[j - 1]); 
                if(cur[j] - cur[j - 1] != 0) {
                    equal = false;
                }
            }

            if(equal) {
                break;
            }

            std::swap(cur, nxt);
        }

        int64_t res = 0;
        for(int j = last.size() - 1; j >= 0; j--) {
            res += last[j]; 
        }

        ans += res;
    }

    std::cout << ans << '\n';
}

void run_case2() {
    int n = A.size();
    int64_t ans = 0;
    for(int i = 0; i < n; i++) {
        std::vector<int64_t> cur(A[i]);
        std::vector<int64_t> first;
        while(true) {
            first.push_back(cur.front());

            int size = cur.size();
            if(size == 1) {
                break;
            }
            
            std::vector<int64_t> nxt;
            bool equal = true;
            for(int j = 1; j < size; j++) {
                nxt.push_back(cur[j] - cur[j - 1]); 
                if(cur[j] - cur[j - 1] != 0) {
                    equal = false;
                }
            }

            if(equal) {
                break;
            }

            std::swap(cur, nxt);
        }

        int64_t res = 0;
        for(int j = first.size() - 1; j >= 0; j--) {
            res = first[j] - res;
        }

        ans += res;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::string S;
    while(std::getline(std::cin, S)) {
        int n = S.size(); 
        A.emplace_back();
        for(int i = 0; i < n; i++) {
            if(is_digit(S[i])) {
                int j = i;
                int64_t x = 0;
                while(i < n && is_digit(S[i])) {
                    x = x * 10 + S[i++] - '0';
                }
                
                if(j && S[j - 1] == '-') {
                    x *= -1;
                }
                A.back().push_back(x); 
            }
        }
    }

    run_case1();
    run_case2();
}
