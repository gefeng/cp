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

    if(N % 7 == 0) {
        std::cout << N << '\n';
        return;
    }

    for(int i = 0; i < 10; i++) {
        if(N % 10 != i) {
            int x = N / 10 * 10 + i;
            if(x % 7 == 0) {
                std::cout << x << '\n';
                return;
            }
        }
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
