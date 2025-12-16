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

    int prefix = 0;
    int ans = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && S[i] == S[j]) {
            i += 1;
        }

        if(S[j] == '0') {
            int len = 0;
            if(j == 0) {
                prefix = i - j;            
            } else if(i == N) {
                len = prefix + i - j; 
            } else {
                len = i - j;
            }
            ans = std::max(ans, len);
        } else {
            if(i == N) {
                ans = std::max(ans, prefix);
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
