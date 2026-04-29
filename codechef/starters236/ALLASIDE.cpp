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
    int changeable = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && S[j] == S[i]) {
            i++;
        }
        if(S[j] == '1') {
            cnt++;
        }
        if(i - j > 1) {
            changeable = 1;
        }
    }

    if(cnt == 0 || !changeable) {
        std::cout << S << '\n';
        return;
    }

    std::string ans(N, '0');
    int st = S.back() == '0' ? N - 2 : N - 1;
    for(int i = st; i >= 0 && cnt; i -= 2, cnt--) {
        ans[i] = '1';
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
