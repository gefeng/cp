#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K1, K2, W, B;
    std::cin >> N >> K1 >> K2 >> W >> B;

    int a = K1 + K2;
    int b = N - K1 + N - K2;
    
    if(W * 2 > a || B * 2 > b) {
        std::cout << "No" << '\n';
        return;
    }

    std::cout << "Yes" << '\n';
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
