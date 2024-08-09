#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 8;

void test() {
    std::vector<int> a(MAX, 0);
    for(int i = 0; i < MAX; i++) {
        a[i] = i;
    }
    do {
        int sum = 0;
        for(int i = 0; i < MAX; i += 2) {
            sum += a[i] & a[i + 1];
        }
        if(sum == MAX - 1) {
            for(int i = 0; i < MAX; i++) {
                std::cout << a[i] << " \n"[i == MAX - 1];
            }
        }
    } while(std::next_permutation(a.begin(), a.end()));
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    if(N == 4 && K == 3) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<std::pair<int, int>> ans;
    std::vector<int> vis(N, 0);
    if(K == N - 1) {
        for(int i = 2; i < N - 2; i++) {
            if(vis[i]) {
                continue;
            }
            ans.emplace_back(i, (N - 1) ^ i);
            vis[i] = 1;
            vis[(N - 1) ^ i] = 1;
        }

        int n = ans.size();
        for(int i = 0; i < n; i++) {
            auto [a, b] = ans[i];
            if((a & 1) == 1) {
                ans[i] = {a, 1};
                ans.emplace_back(b, 0);
                break;
            }
            if((b & 1) == 1) {
                ans[i] = {b, 1};
                ans.emplace_back(a, 0);
                break;
            }
        }
        ans.emplace_back(N - 1, N - 2);
    } else {
        for(int i = 0; i < N; i++) {
            if(vis[i]) {
                continue;
            } 
            if(i == 0) {
                ans.emplace_back(0, (N - 1) ^ K);
                vis[0] = 1;
                vis[(N - 1) ^ K] = 1;
            } else if(i == K) {
                ans.emplace_back(K, N - 1);
                vis[K] = 1;
                vis[N - 1] = 1;
            } else {
                ans.emplace_back(i, (N - 1) ^ i);
                vis[i] = 1;
                vis[(N - 1) ^ i] = 1;
            }
        }
    }
    
    int sum = 0;
    for(int i = 0; i < N / 2; i++) {
        std::cout << ans[i].first << ' ' << ans[i].second << '\n';
        sum += ans[i].first & ans[i].second;
    }

    assert(sum == K);
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
