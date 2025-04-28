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

    if(N == 2) {
        std::cout << (S[0] == 'A' ? "Alice" : "Bob") << '\n';
        return;
    }

    if(S[0] == 'A' && S.back() == 'A') {
        std::cout << "Alice" << '\n';
        return;
    }

    if(S[0] == 'B' && S.back() == 'B') {
        std::cout << "Bob" << '\n';
        return;
    }

    if(S[0] == 'A' && S.back() == 'B') {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(S[i] == 'B') {
                cnt += 1;
            }
        }
        std::cout << (cnt == 1 ? "Alice" : "Bob") << '\n';
        return;
    }

    std::cout << (S[N - 2] == 'A' ? "Alice" : "Bob") << '\n';
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
