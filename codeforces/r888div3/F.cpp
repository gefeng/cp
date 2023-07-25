#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int max_v;
int ans_i;
int ans_j;
int ans_x;

void dfs(std::vector<std::pair<int, int>>& a, int k, int x) {
    if(a.size() <= 1) {
        return;
    }
    if(a.size() == 2) {
        for(int i = k; i >= 0; i--) {
            int b1 = (a[0].first & (1 << i)) == 0 ? 0 : 1;
            int b2 = (a[1].first & (1 << i)) == 0 ? 0 : 1;
            if(b1 == b2 && b1 == 0) {
                x |= 1 << i;
            }
        }
        int res = (a[0].first ^ x) & (a[1].first ^ x);
        if(res > max_v) {
            max_v = res;
            ans_i = a[0].second + 1;
            ans_j = a[1].second + 1;
            ans_x = x;
        }
        return;
    }

    if(k < 0) {
        int res = (a[0].first ^ x) & (a[1].first ^ x);
        if(res > max_v) {
            max_v = res;
            ans_i = a[0].second + 1;
            ans_j = a[1].second + 1;
            ans_x = x;
        }
        return;
    }

    std::vector<std::pair<int, int>> v1;
    std::vector<std::pair<int, int>> v2;
    for(auto [v, i] : a) {
        if(v & (1 << k)) {
            v1.emplace_back(v, i);
        } else {
            v2.emplace_back(v, i);
        }
    }

    dfs(v1, k - 1, x);
    dfs(v2, k - 1, x | (1 << k));
}

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    max_v = -1;
    ans_i = -1;
    ans_j = -1;
    ans_x = 0;

    std::vector<std::pair<int, int>> a(N);
    for(int i = 0; i < N; i++) {
        a[i].first = A[i];
        a[i].second = i;
    }
    dfs(a, K - 1, 0);

    std::cout << ans_i << ' ' << ans_j << ' ' << ans_x << '\n';
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
