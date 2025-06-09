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
    int first = -1;
    int last = -1;
    
    for(int i = 0; i < n; i++) {
        if(S[i] == '1') {
            first = first == -1 ? i : first;
            last = std::max(last, i);
        }
    }

    int ans = 0;
    for(int i = first; i <= last; i++) {
        if(S[i] == '0') {
            ans += 1;
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
