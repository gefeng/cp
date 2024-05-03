#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <functional>

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

    std::vector<int> z = z_function(S);
    z[0] = N;

    auto max_partition = [&](int lcp) {
        int cnt = 0;
        for(int i = 0; i < N; ) {
            if(z[i] >= lcp) {
                cnt += 1;
                i += lcp;
            } else {
                i += 1;
            }
        }
        return cnt;
    };

    std::vector<int> save_lcp(N + 1, 0);
    int n = int(sqrt(N));
    for(int lcp = 1; lcp <= n; lcp++) {
        int cnt = max_partition(lcp);
        for(int i = 1; i <= cnt; i++) {
            save_lcp[i] = std::max(save_lcp[i], lcp);
        }
    }

    for(int k = 1; k <= n; k++) {
        int lo = 1;
        int hi = N;
        int res = 0;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            int cnt = max_partition(mid);
            if(cnt >= k) {
                res = mid; 
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        save_lcp[k] = std::max(save_lcp[k], res);
    }

    
    for(int i = L; i <= R; i++) {
        std::cout << save_lcp[i] << " \n"[i == R];
    }
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
