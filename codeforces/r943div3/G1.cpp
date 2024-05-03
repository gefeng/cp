#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

std::vector<int> z_function(std::string s) {
    int n = s.size();
    std::vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = std::min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void run_case() {
    int N, L, R;
    std::cin >> N >> L >> R;
    
    std::string S;
    std::cin >> S;

    if(L == 1) {
        std::cout << N << '\n';
        return;
    }

    std::vector<int> z = z_function(S);

    int lo = 1;
    int hi = N;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        int cnt = 1;
        for(int i = mid; i < N; ) {
            if(z[i] >= mid) {
                cnt += 1;
                i += mid;
            } else {
                i += 1;
            }
        }

        if(cnt >= L) {
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
