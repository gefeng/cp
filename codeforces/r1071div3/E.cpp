#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N;
    int64_t X, Y;
    std::cin >> N >> X >> Y;

    std::string S;
    std::cin >> S;

    std::vector<int64_t> A(N);
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    if(sum > X + Y) {
        std::cout << "NO" << '\n';
        return;
    }

    int64_t sum_a = 0;
    int64_t sum_b = 0;
    int zero = 0;
    int one = 0;
    for(int i = 0; i < N; i++) {
        int64_t x = A[i] / 2 + 1;
        if(S[i] == '0') {
            sum_a += x;
            zero = 1;
        } else {
            sum_b += x;
            one = 1;
        }
    }

    if(sum_a > X || sum_b > Y) {
        std::cout << "NO" << '\n';
        return;
    }

    if(zero && one) {
        std::cout << "YES" << '\n';
        return;
    }

    if(zero) {
        std::cout << (Y + N <= X ? "YES" : "NO") << '\n';
    } else {
        std::cout << (X + N <= Y ? "YES" : "NO") << '\n';
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
