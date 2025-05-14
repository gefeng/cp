#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(int N, int lv, int k, int id, int l, int r, std::string& ans) {
    int n = (1 << (N + 1 - lv)) - 1;
    if(k == 0) {
        return;
    }
    
    if(n == k) {
        for(int i = l; i <= r; i++) {
            ans[i] = '1';
        }
        return;
    }

    int m = (1 << (N - lv)) - 1;
    int mid = (l + r) / 2;
    if(k >= m) {
        dfs(N, lv + 1, k - m, id * 2 + 1, l, mid, ans);
        dfs(N, lv + 1, m, id * 2 + 2, mid + 1, r, ans);
    } else {
        int x = std::min(m - (N - lv), k);
        dfs(N, lv + 1, x, id * 2 + 1, l, mid, ans);
        dfs(N, lv + 1, k - x, id * 2 + 2, mid + 1, r, ans);
    }
}

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    int n = (1 << (N + 1)) - 1;
    int m = 1 << N;
    std::string ans(m, '0');
    if(K == n || (K <= n - N - 1)) {
        dfs(N, 0, K, 0, 0, m - 1, ans); 
        std::cout << "Yes" << '\n' << ans << '\n';
    } else {
        std::cout << "No" << '\n';
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
