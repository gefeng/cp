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

    int cnt = 0;
    for(int l = 0, r = N - 1; l < r; l++, r--) {
        if(S[l] == S[r]) {
            cnt += 1;
        } else {
            break;
        }
    }

    if(N % 2 == 0) {
        std::cout << ((cnt == N / 2 && cnt == K) || cnt < K ? "NO" : "YES") << '\n';    
    } else {
        std::cout << (K <= cnt ? "YES" : "NO") << '\n';
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
