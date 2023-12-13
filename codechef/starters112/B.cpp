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

    bool has_zero = false;
    for(int i = 0; i < N; i++) {
        if(has_zero) {
            std::cout << "No" << '\n';
            continue;
        }

        if(S[i] == '0') {
            std::cout << "No" << '\n';
            has_zero = true;
        } else {
            std::cout << (i == N - 1 ? "Yes" : "IDK") << '\n';
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
