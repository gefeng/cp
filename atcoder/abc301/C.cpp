#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S, T;
    std::cin >> S >> T;

    std::string atcoder = "atcoder";
    std::array<int, 26> cnt1 = {};
    std::array<int, 26> cnt2 = {};
    int cnt_at1 = 0;
    int cnt_at2 = 0;

    for(char c : S) {
        if(c == '@') {
            cnt_at1 += 1;
        } else {
            cnt1[c - 'a'] += 1;
        }
    }

    for(char c : T) {
        if(c == '@') { 
            cnt_at2 += 1;
        } else {
            cnt2[c - 'a'] += 1;
        }
    }

    for(char c : S) {
        if(c != '@') {
            if(cnt2[c - 'a']) {
                cnt2[c - 'a'] -= 1;
                cnt1[c - 'a'] -= 1;
            } else if(atcoder.find(c) != std::string::npos && cnt_at2) {
                cnt_at2 -= 1;
                cnt1[c - 'a'] -= 1;
            } else {
                std::cout << "No" << '\n';
                return;
            }
        }
    }

    for(char c : T) {
        if(c != '@' && cnt2[c - 'a']) {
            if(cnt1[c - 'a']) {
                cnt1[c - 'a'] -= 1;
                cnt2[c - 'a'] -= 1;
            } else if(atcoder.find(c) != std::string::npos && cnt_at1) {
                cnt_at1 -= 1;
                cnt2[c - 'a'] -= 1;
            } else {
                std::cout << "No" << '\n';
                return;
            }
        }
    }

    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
