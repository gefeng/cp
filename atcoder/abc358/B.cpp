#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, A;
    std::cin >> N >> A;

    std::vector<int> T(N);
    for(int i = 0; i < N; i++) {
        std::cin >> T[i];
    }

    int64_t t = 0;
    for(int i = 0; i < N; i++) {
        if(T[i] >= t) {
            t = T[i] + A;
        } else {
            t = t + A;
        }
        std::cout << t << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
