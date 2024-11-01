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

    if(N == 1) {
        std::cout << 1 << '\n' << 1 << '\n';
        return;
    }
    
    if(K == 1 || K == N) {
        std::cout << -1 << '\n';
        return;
    }

    int l = K - 1;
    int r = N - K;
    
    int t = std::min(l, r);
    
    std::vector<int> ans;
    if(l > t) {
        for(int i = 1; i <= t; i++) {
            ans.push_back(i);
        } 
        ans.push_back(K);
        for(int i = K + 1; i <= N; i++) {
            ans.push_back(i);
        }
    } else {
        for(int i = 1; i <= l; i++) {
            ans.push_back(i);
        }
        ans.push_back(K);
        for(int i = K + 1; i <= t + K; i++) {
            ans.push_back(i);
        }
    }

    int m = ans.size();
    std::cout << m << '\n';
    for(int i = 0; i < m; i++) {
        std::cout << ans[i] << " \n"[i == m - 1];
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
