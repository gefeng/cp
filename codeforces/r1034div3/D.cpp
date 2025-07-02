#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;

    int cnt = std::ranges::count(S, '1');

    if(cnt <= K) {
        std::cout << "Alice" << '\n';
        return;
    }

    std::cout << (K * 2 > N ? "Alice" : "Bob") << '\n';
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
