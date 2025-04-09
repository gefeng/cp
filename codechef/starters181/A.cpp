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

    int bal = 0;
    int64_t ans = 1;
    for(int i = 0; i < N; i++) {
        if(S[i] == '1') {
            bal += 1;
        } else {
            bal -= 1;
        }
        if(bal == 0) {
            ans *= 2; 
        }
    }

    std::cout << ans << '\n';
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
