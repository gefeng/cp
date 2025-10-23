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

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cnt += (S[i] - '0') ^ 1;
    }

    if(cnt == 0 || cnt == N) {
        std::cout << "Bob" << '\n';
        return;
    }
    
    if(S[0] == S.back()) {
        std::cout << "Alice" << '\n';
        return;
    }

    int l = 0;
    int r = N - 1;
    while(l < N && S[l] == S[0]) {
        l += 1;
    }
    while(r >= 0 && S[r] == S.back()) {
        r -= 1;
    }
    
    std::cout << (l > r ? "Bob" : "Alice") << '\n';
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
