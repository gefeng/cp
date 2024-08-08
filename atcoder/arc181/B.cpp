#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    std::string S, X, Y;
    std::cin >> S >> X >> Y;

    int n = S.size();
    
    int64_t a = 0;
    int64_t b = 0;
    int64_t x = 0;
    int64_t y = 0;
    for(char c : X) {
        if(c == '0') {
            a += n; 
        } else {
            x += 1;
        }
    }

    for(char c : Y) {
        if(c == '0') {
            b += n;
        } else {
            y += 1;
        }
    }

    if(a == b) {
        std::cout << "Yes" << '\n';
        return;
    }

    if(x == y) {
        std::cout << "No" << '\n';
        return;
    }

    if((b - a < 0 && x - y > 0) || (b - a > 0 && x - y < 0)) {
        std::cout << "No" << '\n';
        return;
    }

    if((b - a) % (x - y) != 0) {
        std::cout << "No" << '\n';
        return;
    }

    int64_t len = (b - a) / (x - y);
    int64_t t = gcd(n, len);

    for(int i = 0; i < t; i++) {
        for(int j = 0; j < n / t; j++) {
            if(S[i] != S[i + j * t]) {
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

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
