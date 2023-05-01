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

    bool has_poor = false;
    bool has_good = false;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'o') {
            has_good = true;
        }

        if(S[i] == 'x') {
            has_poor = true;
        }
    }

    std::cout << (!has_poor && has_good ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
