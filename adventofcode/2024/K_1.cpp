#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX_T = 25;

int64_t next_int(std::string& s, int& p) {
    int64_t x = 0;
    int n = s.size();
    while(p < n && !std::isdigit(s[p])) {
        p += 1; 
    }

    if(p == n) {
        return -1;
    }

    while(p < n && std::isdigit(s[p])) {
        x = x * 10 + s[p++] - '0'; 
    }

    return x;
}

int count_digits(int64_t x) {
    int cnt = 0;
    while(x) {
        x /= 10;
        cnt += 1;
    }
    return cnt;
}

std::pair<int64_t, int64_t> split(int64_t x) {
    int64_t l = 0;
    int64_t r = 0;
    
    int cnt = count_digits(x);
    
    int64_t base = 1;
    for(int i = 0; i < cnt / 2; i++) {
        int d = x % 10;
        r += d * base; 
        base *= 10;
        x /= 10;
    }

    base = 1;
    for(int i = 0; i < cnt / 2; i++) {
        int d = x % 10;
        l += d * base;
        base *= 10;
        x /= 10;
    }

    return {l, r};
}

void run_case() {
    std::string S;
    std::getline(std::cin, S);

    int p = 0;
    std::vector<int64_t> a;
    while(true) {
        int64_t x = next_int(S, p);
        if(x == -1) {
            break;
        }
        a.push_back(x);
    }

    for(int _{}; _ < MAX_T; _++) {
        std::vector<int64_t> na;
        
        for(int64_t x : a) {
            if(x == 0) {
                na.push_back(1);
                continue;
            } 
            
            int cnt = count_digits(x);
            if(cnt % 2 == 0) {
                auto [l, r] = split(x);
                na.push_back(l);
                na.push_back(r);
            } else {
                na.push_back(x * 2024);
            }
        }

        std::swap(a, na);
    }

    std::cout << a.size() << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
