#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::vector<std::pair<int, int>> a(N);
    for(int i = 0; i < N; i++) {
        a[i] = {A[i], i};
    }
    
    std::sort(a.begin(), a.end());

    auto pre_smaller = [&]() {
        std::vector<int> pre_s(N, -1);
        std::set<int> s;
        for(int i = 0; i < N; i++) {
            auto it = s.upper_bound(a[i].second);
            if(it != s.begin()) {
                it--;
                pre_s[a[i].second] = *it; 
            } 
            s.insert(a[i].second);
        }
        return pre_s;
    };

    auto nxt_smaller = [&]() {
        std::vector<int> nxt_s(N, N);
        std::set<int> s;
        for(int i = 0; i < N; i++) {
            auto it = s.upper_bound(a[i].second);
            if(it != s.end()) {
                nxt_s[a[i].second] = *it;
            }
            s.insert(a[i].second);
        }
        return nxt_s;
    };

    auto pre_pre_smaller = [&]() {
        std::vector<int> pre_pre_s(N, -1);
        std::set<int> s;
        for(int i = 0; i < N; i++) {
            auto it = s.upper_bound(a[i].second);
            if(it != s.begin()) {
                it--;
                if(it != s.begin()) {
                    it--;
                    pre_pre_s[a[i].second] = *it;
                }
            }
            s.insert(a[i].second);
        }
        return pre_pre_s;
    };

    auto nxt_nxt_smaller = [&]() {
        std::vector<int> nxt_nxt_s(N, N);
        std::set<int> s;
        for(int i = 0; i < N; i++) {
            auto it = s.upper_bound(a[i].second);
            if(it != s.end()) {
                it++;
                if(it != s.end()) {
                    nxt_nxt_s[a[i].second] = *it;
                }
            }
            s.insert(a[i].second);
        }
        return nxt_nxt_s;
    };

    std::vector<int> pre_s = pre_smaller(); 
    std::vector<int> nxt_s = nxt_smaller();
    std::vector<int> pre_pre_s = pre_pre_smaller();
    std::vector<int> nxt_nxt_s = nxt_nxt_smaller();
    
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        int l = pre_s[i];
        int r = nxt_s[i];
        sum += int64_t(i - l) * (r - i) * A[i];
    }

    std::vector<int64_t> dp(N, sum); 
    std::vector<int64_t> diff(N + 1, 0);
    for(int i = 0; i < N; i++) {
        int l = pre_s[i];
        int r = nxt_s[i];

        dp[i] -= int64_t(i - l) * (r - i) * A[i];
        
        if(l != -1) {
            dp[l] -= int64_t(i - l) * (r - i) * A[i];
            dp[l] += int64_t(i - pre_pre_s[i] - 1) * (r - i) * A[i];
        }
        if(r != N) {
            dp[r] -= int64_t(i - l) * (r - i) * A[i];
            dp[r] += int64_t(i - l) * (nxt_nxt_s[i] - i - 1) * A[i];
        }

        diff[l + 1] -= int64_t(r - i) * A[i];
        diff[i] += int64_t(r - i) * A[i];
        diff[i + 1] -= int64_t(i - l) * A[i];
        diff[r] += int64_t(i - l) * A[i];
    }
    
    for(int i = 0; i < N; i++) {
        diff[i] = i ? diff[i] + diff[i - 1] : diff[i];
        std::cout << dp[i] + diff[i] << " \n"[i == N - 1];
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
