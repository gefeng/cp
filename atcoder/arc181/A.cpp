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
    
    std::vector<int> P(N);
    for(int i = 0; i < N; i++) {
        std::cin >> P[i];
        P[i] -= 1;
    }

    bool good = true;
    for(int i = 0; i < N; i++) {
        if(P[i] != i) {
            good = false;
            break;
        }
    }

    if(good) {
        std::cout << 0 << '\n';
        return;
    }

    if(P[0] == N - 1 && P[N - 1] == 0) {
        std::cout << 3 << '\n';
        return;
    }

    int max_v = -1;
    for(int i = 0; i < N; i++) {
        if(P[i] == i) {
            if(max_v < i) {
                std::cout << 1 << '\n';
                return;
            }
        }

        max_v = std::max(max_v, P[i]);
    }

    std::cout << 2 << '\n'; 
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
