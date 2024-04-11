#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, A, B;
    std::cin >> N >> A >> B;

    std::vector<int> D(N);
    for(int i = 0; i < N; i++) {
        std::cin >> D[i];
    }

    // [0 ... A-1]
    int64_t l = 0;
    int64_t r = A - 1;
    int64_t n = A + B;
    for(int i = 1; i < N; i++) {
        int64_t d = D[i] - D[i - 1]; 
         
        l += d;
        r += d;
        l %= n;
        r %= n;

        if(r < l || l < A) {
            if(r < l) {
                l = 0;
            } else {
                r = A - 1;
            }
            continue;
        }
        std::cout << "No" << '\n';
        return;
    }

    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
