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
    std::string T;
    std::cin >> S >> T;

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(T[i] == '1') {
            if(S[i] == '0') {
                S[i] = '2';
            } else if(i - 1 >= 0 && S[i - 1] == '1') {
                S[i - 1] = '2'; 
            } else if(i + 1 < N && S[i + 1] == '1') {
                S[i + 1] = '2';
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(S[i] == '2') {
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
