#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9);
constexpr int MAX = 435;

std::vector<int> a;
std::vector<int> b;
std::vector<int> dp(MAX + 1, INF);
std::vector<int> pre(MAX + 1, -1);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    int ub = N * (N - 1) / 2;
    int t = ub - K; 
    
    if(dp[t] > N) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<int> seg;
    int sum = t;
    int now = pre[sum];
    while(now != -1) {
        seg.push_back(now);
        sum -= a[now];
        now = pre[sum];
    }

    std::vector<int> ans(N, 0);
    int p = N - 1;
    now = 1;
    for(int s : seg) {
        int nxt = now + b[s];
        for(int i = 0, j = nxt - 1; i < b[s]; i++, j--) {
            ans[p--] = j;
        }
        now = nxt;
    }

    for(int i = 0, j = N; i < N; i++, j--) {
        if(ans[i] == 0) {
            ans[i] = j;
        } else {
            break;
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    for(int i = 1, j = 2; i <= MAX; i += j, j++) {
        a.push_back(i);
        b.push_back(j);
    }

    int n = a.size();
    dp[0] = 0;

    for(int i = 1; i <= MAX; i++) {
        for(int j = 0; j < n; j++) {
            if(i - a[j] >= 0 && dp[i - a[j]] != INF) {
                if(dp[i] > dp[i - a[j]] + b[j]) {
                    dp[i] = dp[i - a[j]] + b[j];
                    pre[i] = j;
                }
            }
        }
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
