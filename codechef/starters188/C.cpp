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

    std::vector<int> pre_a(N, 0);
    std::vector<int> nxt_c(N, 0);
    
    for(int i = 0; i < N; i++) {
        if(S[i] == 'A') {
            pre_a[i] = i == 0 ? 1 : pre_a[i - 1] + 1; 
        } else if(S[i] == 'C') {
            pre_a[i] = 0;
        } else {
            pre_a[i] = i == 0 ? 0 : pre_a[i - 1];
        }
    }

    for(int i = N - 1; i >= 0; i--) {
        if(S[i] == 'A') {
            nxt_c[i] = 0;
        } else if(S[i] == 'C') {
            nxt_c[i] = i == N - 1 ? 1 : nxt_c[i + 1] + 1;
        } else {
            nxt_c[i] = i == N - 1 ? 0 : nxt_c[i + 1];
        }
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'B') {
            ans += std::max(pre_a[i], nxt_c[i]);
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
