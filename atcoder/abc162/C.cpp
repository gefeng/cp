#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int K;
    std::cin >> K;

    LL ans = 0LL;
    for(int a = 1; a <= K; a++) {
        for(int b = 1; b <= K; b++) {
            for(int c = 1; c <= K; c++) {
                int g = gcd(gcd(a, b), c);
                ans += g;
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
