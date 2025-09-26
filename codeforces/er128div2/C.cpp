#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;
    std::cin >> S;

    int n = S.size();
    
    std::vector<int> pos;
    std::vector<int> psum(n + 1, 0);
    for(int i = 0; i < n; i++) {
        if(S[i] == '0') {
            pos.push_back(i);
            psum[i + 1] = psum[i];
        } else {
            psum[i + 1] = psum[i] + 1;
        }
    }

    int m = pos.size();
    int lo = 0;
    int hi = n;
    int ans = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;        
        
        bool ok = true;
        if(mid <= m) {
            ok = false;
            for(int i = 0; i <= m - mid; i++) {
                int l = i == 0 ? -1 : pos[i - 1];
                int r = i + mid < m ? pos[i + mid] : n;
                int cnt = psum[l + 1] + psum[n] - psum[r];
                if(cnt <= mid) {
                    ok = true;
                    break;
                }
            } 
        }

        if(ok) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
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
