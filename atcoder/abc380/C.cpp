#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;
    
    int k = 0;
    int p = -1;
    int len = 0;
    std::string ans = "";
    for(int i = 0; i < N; ) {
        if(S[i] == '0') {
            i += 1;
        } else {
            int j = i;
            while(i < N && S[i] == S[j]) {
                i += 1;
            }
            k += 1;
            
            if(k == K) {
                ans = S.substr(0, p + len) + S.substr(j, i - j) + S.substr(p + len, j - p - len) + S.substr(i, N - i); 
                std::cout << ans << '\n';
                return;
            }
            
            p = j;
            len = i - j;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
