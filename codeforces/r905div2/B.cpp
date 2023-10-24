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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = 0;
    if(K == 2) {
        bool eve = false;
        for(int x : A) {
            if(x % 2 == 0) {
                eve = true;
                break;
            }
        }
        ans = eve ? 0 : 1;
    } else if(K == 3) {
        std::array<int, 3> cnt = {};
        for(int x : A) {
            cnt[x % 3] += 1;
        }

        if(cnt[0]) {
            ans = 0;
        } else {
            if(cnt[2]) {
                ans = 1;
            } else {
                ans = 2;
            }
        }
    } else if(K == 4) {
        bool mul4 = false;
        int cnt_eve = 0;
        for(int x : A) {
            if(x % 4 == 0) {
                mul4 = true; 
            }
            if(x % 2 == 0) {
                cnt_eve += 1;
            }
        }
        if(mul4 || cnt_eve > 1) {
            ans = 0;
        } else {
            if(cnt_eve == 1) {
                ans = 1;
            } else {
                for(int x : A) {
                    if((x + 1) % 4 == 0) {
                        ans = 1;     
                    } 
                }
            
                ans = ans == 0 ? 2 : ans;
            }
        }
    } else {
        std::array<int, 5> cnt = {};
        for(int x : A) {
            cnt[x % 5] += 1;
        }

        if(cnt[0]) {
            ans = 0;
        } else {
            for(int i = 4; i > 0; i--) {
                if(cnt[i]) {
                    ans = 5 - i;
                    break;
                }
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
