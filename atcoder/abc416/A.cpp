#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, L, R;
    std::cin >> N >> L >> R;
    L -= 1;
    R -= 1;

    std::string S;
    std::cin >> S;

    for(int i = L; i <= R; i++) {
        if(S[i] == 'x') {
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
