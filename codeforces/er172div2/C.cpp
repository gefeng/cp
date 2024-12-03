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
    
    std::vector<int> bal(N, 0);
    for(int i = N - 1; i >= 0; i--) {
        bal[i] = (i == N - 1 ? 0 : bal[i + 1]) + (S[i] == '0' ? -1 : 1);
    }

    std::sort(bal.begin() + 1, bal.end(), std::greater<int>());
    
    int64_t sum = 0;
    for(int i = 1; i < N; i++) {
        sum += bal[i];
        if(sum >= K) {
            std::cout << i + 1 << '\n';
            return;
        }
    }

    std::cout << -1 << '\n';
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
