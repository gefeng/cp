#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(N == 1) {
        std::cout << 0 << '\n';
        return;
    }

    std::sort(A.begin(), A.end());

    std::map<int, int> m;
   
    for(int i = 0; i < N; i++) {
        int l = 0;
        int r = 0;
        
        if(i + 1 < N) {
            l = A[i + 1] - A[i] + 1;
            r = A[i];
            if(l <= r) {
                m[l] = std::max(m[l], r);
            }
        }

        if(i + 1 < N) {
            l = std::max(A[i], A[i + 1] - A[i] + 1);
            r = A[i + 1];
            if(l <= r) {
                m[l] = std::max(m[l], r);
            }
        }

        if(i) {
            l = A[i];
            r = A[i] + A[i - 1] - 1;
            if(l <= r) {
                m[l] = std::max(m[l], r);
            }
        }
    } 

    int now_l = -1;
    int now_r = -1;
    int ans = 0;
    for(auto [l, r] : m) {
        if(now_r != -1 && l <= now_r) {
            now_r = std::max(now_r, r);
        } else {
            if(now_r != -1) {
                ans += now_r - now_l + 1;
            }

            now_l = l;
            now_r = r;
        }
    }

    if(now_r != -1) {
        ans += now_r - now_l + 1;
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
