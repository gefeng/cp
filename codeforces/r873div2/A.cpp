#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    // (n + 1) * n / 2 
    // 2 + 4 + 6 + 8 + 10 12 14

    int N;
    std::cin >> N;

    if(N % 2 == 1) {
        for(int i = 1; i <= N; i++) {
            std::cout << i << " \n"[i == N];
        }
    } else {
        for(int i = 1; i <= N; i++) {
            std::cout << i * 2 << " \n"[i == N];
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
