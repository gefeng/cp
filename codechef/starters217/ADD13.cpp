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

    if(M < N || (M - N) % 2 != 0) {
        std::cout << "NO" << '\n';
        return;
    }

    int x = (M - N) / 2;
    int y = N - x;

    std::cout << ((x < 0 || y < 0) ? "NO" : "YES") << '\n';
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
