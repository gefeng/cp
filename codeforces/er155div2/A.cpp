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

    std::vector<int> S(N);
    std::vector<int> E(N);
    for(int i = 0; i < N; i++) {
        std::cin >> S[i] >> E[i];
    }

    bool win = true;
    for(int i = 1; i < N; i++) {
        if(S[i] >= S[0] && E[i] >= E[0]) {
            win = false;
            break;
        }
    }

    std::cout << (win ? S[0] : -1) << '\n';
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
