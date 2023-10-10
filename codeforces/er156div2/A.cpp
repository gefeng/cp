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

    if(N <= 6) {
        std::cout << "No" << '\n';
        return;
    }

    int a = 1;
    int b = 2;
    int c = 0;
    c = N - a - b;
    
    if(c % 3 == 0) {
        b += 2;
        c -= 2;
    }

    if(a == b || b == c || a == c) {
        std::cout << "No" << '\n';
        return;
    }

    std::cout << "Yes" << '\n' << a << ' ' << b << ' ' << c << '\n';
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
