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
    
    int cnt = 0;
    for(int i = 0; i <= N - 3; i++) {
        if(S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C') {
            cnt += 1;
        } 
    }
    
    for(int i = 0; i < Q; i++) {
        int P;
        char C;
        std::cin >> P >> C;
        P -= 1;
        
        char c = S[P];
        if((c == 'A' && P + 2 < N && S[P + 1] == 'B' && S[P + 2] == 'C') || 
                (c == 'B' && P - 1 >= 0 && P + 1 < N && S[P - 1] == 'A' && S[P + 1] == 'C') || 
                (c == 'C' && P - 2 >= 0 && S[P - 2] == 'A' && S[P - 1] == 'B')) {
            cnt -= 1;
        }

        if((C == 'A' && P + 2 < N && S[P + 1] == 'B' && S[P + 2] == 'C') || 
                (C == 'B' && P - 1 >= 0 && P + 1 < N && S[P - 1] == 'A' && S[P + 1] == 'C') || 
                (C == 'C' && P - 2 >= 0 && S[P - 2] == 'A' && S[P - 1] == 'B')) {
            cnt += 1;
        }

        S[P] = C;
        std::cout << cnt << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
