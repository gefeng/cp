#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;
    std::cin >> S;

    int n = S.size();

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int64_t P;
        std::cin >> P;
        P -= 1;
        
        int64_t r = P % n;
        int64_t k = (P - r) / n;
        int64_t cnt = __builtin_popcountll(k);
        
        char c = S[r];
        if(cnt % 2 == 1) {
            c = c >= 'a' && c <= 'z' ? char(c - 'a' + 'A') : char(c - 'A' + 'a');
        }

        std::cout << c << " \n"[i == Q - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
