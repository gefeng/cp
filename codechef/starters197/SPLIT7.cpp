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

    int lo = 1;
    int hi = N;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;

        int cnt = 0;
        int one = 0;
        int zero = 0;
        for(int i = 0; i < N; i++) {
            if(one + zero == 0) {
                if(S[i] == '0') {
                    zero += 1;
                } else {
                    one += 1;
                }
            } else {
                if(S[i] == '0') {
                    zero += 1;
                    if(one) {
                        one -= 1;
                    }
                } else {
                    one += 1;
                }
            }

            if(zero + one == mid) {
                cnt += 1;
                zero = 0;
                one = 0;
            }
        }

        if(cnt >= K) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
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
