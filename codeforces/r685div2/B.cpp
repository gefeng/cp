#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::string S;
    std::cin >> S;

    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;
        
        bool found = false;
        for(int j = 0; j < L; j++) {
            if(S[j] == S[L]) {
                found = true;
                break;
            }
        }

        if(found) {
            std::cout << "Yes" << '\n';
            continue;
        }

        for(int j = R + 1; j < N; j++) {
            if(S[j] == S[R]) {
                found = true;
                break;
            }
        }

        std::cout << (found ? "Yes" : "No") << '\n';
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
