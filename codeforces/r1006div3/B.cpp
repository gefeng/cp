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

    int a = 0;
    int b = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '_') {
            b += 1;
        } else {
            a += 1;
        }
    }

    if(a < 2 || b == 0) {
        std::cout << 0 << '\n';
        return;
    }

    std::cout << (int64_t(a) / 2) * ((a + 1) / 2) * b << '\n';
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
