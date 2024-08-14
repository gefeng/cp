#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, A, B;
    std::cin >> N >> A >> B;

    std::string S;
    std::cin >> S;

    if(B >= 0) {
        std::cout << (A + B) * N << '\n';
        return;
    }
    
    int cnt_0 = 0;
    int cnt_1 = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && S[i] == S[j]) {
            i += 1;
        }
        if(S[j] == '0') {
            cnt_0 += 1;
        } else {
            cnt_1 += 1;
        }
    }

    int ans = A * N + B * (std::min(cnt_0, cnt_1) + 1);
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
