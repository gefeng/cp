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

    int sum = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'B') {
            sum += 1;
        }
    }

    if(sum == K) {
        std::cout << 0 << '\n';
        return;
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'B') {
            cnt += 1;
        }

        if(i + 1 + sum - cnt == K) {
            std::cout << 1 << '\n' << i + 1 << ' ' << 'B' << '\n';
            return;
        }

        if(sum - cnt == K) {
            std::cout << 1 << '\n' << i + 1 << ' ' << 'A' << '\n';
            return;
        }
    }
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
