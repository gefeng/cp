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

    int ans = 0;
    if(cnt_0 == cnt_1) {
        ans = 1;
    } else if(cnt_0 > cnt_1) {
        if(cnt_1) {
            ans = 2;
        } else {
            ans = N <= 2 ? N : 2;
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
