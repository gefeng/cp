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

    int s1 = 0;
    int s2 = 0;
    for(int i = 0; i < N; i++) {
        int X, Y;
        std::cin >> X >> Y;
        s1 += X;
        s2 += Y;
    }

    if(s1 == s2) {
        std::cout << "Draw" << '\n';
        return;
    }

    std::cout << (s1 > s2 ? "Takahashi" : "Aoki") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
