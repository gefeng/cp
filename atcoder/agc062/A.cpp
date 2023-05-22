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

    for(int i = N - 1; i > 0; i--) {
        if(S[i] == 'A' && S[i - 1] == 'B') {
            std::cout << "A" << '\n';
            return;
        }
    } 

    bool has_b = false;
    for(int i = 0; i < N; i++) { 
        if(S[i] == 'B') {
            has_b = true;
            break;
        }
    }

    std::cout << (has_b ? "B" : "A") << '\n';
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
