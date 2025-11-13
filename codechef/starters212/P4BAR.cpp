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

    int cnt0 = 0;
    int cnt1 = 0;
    for(int i = 0; i < N - 1; i++) {
        if(S[i] == S[i + 1]) {
            if(S[i] == '0') {
                cnt0 += 1;
            } else {
                cnt1 += 1;
            }
        } 
    }

    int ans = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && S[i] == S[j]) {
            i += 1;
        }
        
        if(S[j] == '0') {
            if(j || i < N) {
                for(int k = j; k < i - 1; k++) {
                    if(cnt1 < cnt0) {
                        cnt1 += 1;
                        cnt0 -= 1;
                        ans += 1;
                    } 
                }
            } else {
                ans = N / 2;;
            }
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
