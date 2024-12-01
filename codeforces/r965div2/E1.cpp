#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N, X;
    std::cin >> N >> X;

    std::vector<int> A(N);
    std::vector<std::pair<int, int>> a(N);
    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        a[i] = {A[i], i};
        psum[i + 1] = psum[i] + A[i];
    }

    std::vector<int> pre(N, -1);
    std::vector<int> nxt(N, N);
    std::vector<int> s;
    
    for(int i = 0; i < N; i++) {
        while(!s.empty() && A[s.back()] <= A[i]) {
            s.pop_back();
        }
        
        if(!s.empty()) {
            pre[i] = s.back();
        }

        s.push_back(i);
    }

    s.clear();
    for(int i = N - 1; i >= 0; i--) {
        while(!s.empty() && A[s.back()] <= A[i]) {
            s.pop_back();
        }
        
        if(!s.empty()) {
            nxt[i] = s.back();
        }
        
        s.push_back(i);
    }

    std::sort(a.begin(), a.end());
    std::vector<int> dp(N, 0);
    
    int ans = 0;
    for(int i = N - 1; i >= 0; i--) {
        auto [v, j] = a[i];
        int l = pre[j];
        int r = nxt[j];
        int64_t sum = psum[r] - psum[l + 1]; 

        if(l == -1 && r == N) {
            dp[j] = 1; 
        } else if(l == -1) {
            dp[j] = sum >= A[r] && dp[r];
        } else if(r == N) {
            dp[j] = sum >= A[l] && dp[l];
        } else {
            dp[j] = (sum >= A[l] && dp[l]) || (sum >= A[r] && dp[r]);
        }
    }

    ans = std::accumulate(dp.begin(), dp.end(), 0);
    
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
