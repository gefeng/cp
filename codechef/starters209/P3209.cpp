#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <numeric>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> a(N, 0);
    std::iota(a.begin(), a.end(), 1);
    
    std::ranges::sort(a, [&](int x, int y) {
                int g1 = gcd(x, N);
                int g2 = gcd(y, N);
                if(g1 == g2) {
                    return x < y;
                }
                return g1 > g2;
            });

    for(int i = 0; i < N; i++) {
        std::cout << a[i] << " \n"[i == N - 1];
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
