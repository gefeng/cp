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

    std::string t = "1100";

    int n = S.size();
    int cnt = 0;
    for(int i = 0; i <= n - 4; i++) {
        if(S.substr(i, 4) == t) {
            cnt += 1;
        }
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int P, V;
        std::cin >> P >> V;
        P -= 1;

        if(n >= 4 && S[P] - '0' != V) {
            char c = S[P];
            if(c == '1') {
                if((P <= n - 4 && S.substr(P, 4) == t) || (P - 1 >= 0 && P <= n - 3 && S.substr(P - 1, 4) == t)) {
                    cnt -= 1;
                }    
                S[P] = '0';
                if((P - 2 >= 0 && P + 1 < n && S.substr(P - 2, 4) == t) || (P - 3 >= 0 && S.substr(P - 3, 4) == t)) {
                    cnt += 1;
                }
            } else {
                if((P - 2 >= 0 && P + 1 < n && S.substr(P - 2, 4) == t) || (P - 3 >= 0 && S.substr(P - 3, 4) == t)) {
                    cnt -= 1;
                }
                S[P] = '1';
                if((P <= n - 4 && S.substr(P, 4) == t) || (P - 1 >= 0 && P <= n - 3 && S.substr(P - 1, 4) == t)) {
                    cnt += 1;;
                }    
            }
        }

        std::cout << (cnt ? "Yes" : "No") << '\n';
    }
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
