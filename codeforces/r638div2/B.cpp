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
    std::vector<int> seen(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        seen[A[i]] += 1;
    }

    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        if(seen[i]) {
            cnt += 1;
        }
    }

    if(cnt > K) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int> ans;
    int r = 0;
    int l = 0;

    std::vector<int> added(N + 1, 0);
    while(r < N && ans.size() != K && !added[A[r]]) {
        ans.push_back(A[r]);
        added[A[r]] = 1;
        r += 1;
    }
    
    for(int i = 1; i <= N; i++) {
        if(!added[i] && seen[i]) {
            ans.push_back(i);
        }
    }
    
    while(r < N && ans.size() != K) {
        ans.push_back(A[r++]);
    }

    while(r < N) {
        if(A[r] != ans[l]) {
            ans.push_back(ans[l++]);
        } else {
            ans.push_back(A[r++]);
            l += 1;
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
