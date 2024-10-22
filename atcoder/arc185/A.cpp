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
    
    int64_t sum = int64_t(N) * (N + 1);
    int64_t rem = sum % M;

    if(sum > M && rem > 0 && rem <= N) {
        std::cout << "Bob" << '\n';
    } else {
        std::cout << "Alice" << '\n'; 
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
