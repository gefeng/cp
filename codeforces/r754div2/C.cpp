#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(1e9);

void run_case(int t) {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    if(t == 6912) {
        std::cout << S << '\n';
    }

    std::vector<int> psum_b(N + 1, 0);
    std::vector<int> psum_c(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        psum_b[i] = psum_b[i - 1] + (S[i - 1] == 'b' ? 1 : 0);
        psum_c[i] = psum_c[i - 1] + (S[i - 1] == 'c' ? 1 : 0);
    }

    std::vector<int> a;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'a') {
            a.push_back(i);
        }
    }

    int m = a.size();
    if(m < 2) {
        std::cout << -1 << '\n';
        return;
    }

    auto is_good = [&](int l, int r) {
        int cnt_a = r - l + 1;
        int cnt_b = psum_b[a[r] + 1] - psum_b[a[l]];
        int cnt_c = psum_c[a[r] + 1] - psum_c[a[l]];
        return cnt_a > cnt_b && cnt_a > cnt_c && a[r] - a[l] + 1 >= 2;
    };

    int ans = INF;
    for(int i = 0; i < m; i++) {
        for(int j = i + 1, k = 0; j < m && k < 2; j++, k++) {
            if(is_good(i, j)) {
                ans = std::min(ans, a[j] - a[i] + 1);
            }
        } 
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    // while(T--) {
    //     run_case();
    // }
    for(int i = 1; i <= T; i++) {
        run_case(i);
    }
}
