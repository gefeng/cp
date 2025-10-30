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
    int ans = 0;
    int neg = 0;
    for(int i = 0; i < N; i++) {
        bal += S[i] == '0' ? 1 : -1;
        if(bal < 0) {
            neg = 1;
            bal = 0;
        }
    }

    if(bal) {
        ans += 1;
    }
    if(neg) {
        ans += 1;
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
