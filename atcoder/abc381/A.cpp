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

    std::string S;
    std::cin >> S;

    if(N % 2 == 0) {
        std::cout << "No" << '\n';
        return;
    }

    for(int i = 0; i < N / 2; i++) {
        if(S[i] != '1') {
            std::cout << "No" << '\n';
            return;
        }
    }

    if(S[N / 2] != '/') {
        std::cout << "No" << '\n';
        return;
    }

    for(int i = N / 2 + 1; i < N; i++) {
        if(S[i] != '2') {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
