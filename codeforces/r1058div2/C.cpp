#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    if(N == 0) {
        std::cout << "YES" << '\n';
        return;
    }

    std::array<int, 60> bits = {};
    
    for(int i = 0; i < 30; i++) {
        if(N & (1 << i)) {
            bits[i] = 1;
        }
    }

    int l = -1;
    int r = -1;
    for(int i = 0; i < 30; i++) {
        if(bits[i] == 1) {
            l = i;
            break;
        }
    }

    for(int i = 29; i >= 0; i--) {
        if(bits[i] == 1) {
            r = i;
            break;
        }
    }

    r = r + l;
    l = 0;

    while(l <= r) {
        if(bits[l] != bits[r]) {
            std::cout << "NO" << '\n';
            return;
        }
        if(l == r && bits[l] == 1) {
            std::cout << "NO" << '\n';
            return;
        }
        l += 1;
        r -= 1;
    }

    std::cout << "YES" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
