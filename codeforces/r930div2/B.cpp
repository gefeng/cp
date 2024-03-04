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

    std::string S, T;
    std::cin >> S >> T;
    
    std::string ans = "";
    ans.push_back(S[0]);
    int p = N - 1;
    for(int i = 0; i < N - 1; i++) { 
        if(S[i + 1] <= T[i]) {
            ans.push_back(S[i + 1]);
        }

        if(S[i + 1] > T[i]) {
            p = i;
            break;
        }
    }

    for(int i = p; i < N; i++) {
        ans.push_back(T[i]);
    }

    int cnt = 0;
    while(p) {
        if(T[p - 1] == S[p]) {
            cnt += 1;
            p -= 1;
        } else {
            break;
        }
    }

    std::cout << ans << '\n' << cnt + 1 << '\n';
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
