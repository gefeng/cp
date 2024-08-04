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

    if(A == 1) {
        std::cout << ((N - 1) % B == 0 ? "Yes" : "No") << '\n';
        return;
    }

    for(int64_t x = 1; x <= N; x *= A) {
        int64_t d = N - x;
        if(d % B == 0) {
            std::cout << "Yes" << '\n';
            return;
        }
    }

    std::cout << "No" << '\n';
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
