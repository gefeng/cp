#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::string t(S);
    std::ranges::sort(t);

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] != t[i]) {
            ans += 1;
        }
    }
    ans = (ans + 1) / 2;
    
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
