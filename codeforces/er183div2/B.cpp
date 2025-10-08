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
    
    if(N == K) {
        std::cout << std::string(N, '-') << '\n';
        return;
    }

    int cnt0 = 0;
    int cnt1 = 0;
    int cnt_qm = 0;
    for(int i = 0; i < K; i++) {
        if(S[i] == '1') {
            cnt1 += 1;
        } else if(S[i] == '2') {
            cnt_qm += 1;
        } else {
            cnt0 += 1;
        }
    }

    int cnt_m = N - cnt0 - cnt1;
    std::string prefix(cnt0, '-');
    std::string suffix(cnt1, '-'); 
    std::string ans = prefix;
    
    if(cnt_qm * 2 >= cnt_m) {
        for(int i = 0; i < cnt_m; i++) {
            ans.push_back('?');
        }
    } else {
        for(int i = 0; i < cnt_qm; i++) {
            ans.push_back('?');
        }
        for(int i = 0; i < cnt_m - cnt_qm * 2; i++) {
            ans.push_back('+');
        }
        for(int i = 0; i < cnt_qm; i++) {
            ans.push_back('?');
        }
    }
    ans.append(suffix);
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
