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

    for(int i = 0; i < N; i++) {
        if(i == 0) {
            std::cout << 1 << '\n';
            continue;
        }
        std::cout << 1 << ' ';
        for(int j = 1; j < i; j++) {
            std::cout << 0 << ' ';
        }
        std::cout << 1 << '\n';
    }
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
