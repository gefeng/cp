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
    
    if(N == 1) {
        std::cout << S[0] << '\n';
        return;
    }

    std::string ans(N, S[0]);
    
    int n = S.size();
    for(int i = 0; i <= n - N; i++) {
        bool ok = false;
        for(int j = 0; j < N; j++) {
            if(ans[j] == S[i + j]) {
                ok = true;
                break; 
            }
        }

        if(!ok) {
            ans = std::string(N, (char)(((ans[N - 1] - '0') ^ 1) + '0'));
            break;
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
