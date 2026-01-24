#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::string S, T;
    std::cin >> S >> T;

    std::array<int, 26> a = {};
    std::array<int, 26> b = {};
    
    for(char c : S) {
        a[c - 'a'] += 1;
    }

    for(char c : T) {
        b[c - 'a'] += 1;
    }

    auto check_a = [&](std::string& s) {
        for(char c : s) {
            if(!a[c - 'a']) {
                return false;
            }
        }
        return true;
    };

    auto check_b = [&](std::string& s) {
        for(char c : s) {
            if(!b[c - 'a']) {
                return false;
            }
        }
        return true;
    };

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        std::string X;
        std::cin >> X;
        
        bool is_a = check_a(X);
        bool is_b = check_b(X);
        
        if(is_a && is_b) {
            std::cout << "Unknown" << '\n';
        } else {
            std::cout << (is_a ? "Takahashi" : "Aoki") << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
