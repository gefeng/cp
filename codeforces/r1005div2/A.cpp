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

    bool one = false;
    int ans = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && S[j] == S[i]) {
            i += 1;
        }
        if(S[j] == '0') {
            if(one) {
                ans += 2;
                one = false;
            }
        } else {
            one = true;
            if(i == N) {
                ans += 1;
            }
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
