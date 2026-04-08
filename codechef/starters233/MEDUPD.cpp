#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;
    
    std::string S;
    std::cin >> S;

    bool alt = true;
    for(int i = 0; i < N; i++) {
        if(S[i] == S[(i + 1) % N]) {
            alt = false;
        }
    }

    if(alt) {
        std::cout << -1 << '\n';
        return;
    }

    int ans = 1;

    S.append(S);
    int max_v = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '0') {
            int j = i;
            while(i + 1 < N * 2 && S[i + 1] != S[i]) {
                i++;
            }
            max_v = std::max(max_v, (i - j) / 2);
        }
    } 

    for(int i = 0; i < N; i++) {
        if(S[i] == '1') {
            int j = i;
            while(i + 1 < N * 2 && S[i + 1] != S[i]) {
                i++;
            }
            max_v = std::max(max_v, (i - j) / 2);
        }
    }

    ans += max_v;

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
