#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X;
    std::cin >> X;

    int a = 0;
    int b = 0;
    int i = 30;
    for(; i >= 0; i--) {
        if(X & (1 << i)) {
            b |= 1 << i;
            break;
        }
    }

    i--;
    for(; i >= 0; i--) {
        if(X & (1 << i)) {
            a |= 1 << i;
        }
    }

    std::cout << a << ' ' << b << '\n';
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
