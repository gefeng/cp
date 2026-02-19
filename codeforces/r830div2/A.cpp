#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int g = A[0];
    for(int i = 0; i < N; i++) {
        g = gcd(g, A[i]);
    }

    if(g == 1) {
        std::cout << 0 << '\n';
        return;
    }
    if(N == 1) {
        std::cout << 1 << '\n';
        return;
    }

    int ans = 0;
    if(gcd(g, gcd(A.back(), N)) == 1) {
        ans = 1;
    } else if(gcd(g, gcd(A[N - 2], N - 1)) == 1) {
        ans = 2;
    } else {
        ans = 3;
    }

    std::cout << ans << '\n';
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
