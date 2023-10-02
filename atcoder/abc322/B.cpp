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

    std::string S, T;
    std::cin >> S >> T;

    bool prefix = true;
    bool suffix = true;
    for(int i = 0; i < N; i++) {
        if(S[i] != T[i]) {
            prefix = false;
            break;
        }
    }

    for(int i = N - 1, j = M - 1; i >= 0; i--, j--) {
        if(S[i] != T[j]) {
            suffix = false;
            break;
        }
    }

    if(prefix && suffix) {
        std::cout << 0 << '\n';
    } else if(prefix) {
        std::cout << 1 << '\n';
    } else if(suffix) {
        std::cout << 2 << '\n';
    } else {
        std::cout << 3 << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
