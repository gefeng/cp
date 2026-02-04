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
    
    std::array<int, 26> f = {};
    
    for(int i = 0; i < N; i++) {
        if(S[i] >= 'a' && S[i] <= 'z') {
            f[S[i] - 'a'] += 1;
        } else {
            f[S[i] - 'A'] += 1;
        }
    }

    std::ranges::sort(f);
    
    std::cout << f[25] + f[24] << '\n';
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
