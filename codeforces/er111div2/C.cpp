#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> pre_smaller(N, -1);
    std::vector<int> pre_greater(N, -1);
    std::vector<int> nxt_smaller(N, N);
    std::vector<int> nxt_greater(N, N);

    std::vector<int> s;
    for(int i = 0; i < N; i++) {
        while(!s.empty() && A[s.back()] > A[i]) {
            s.pop_back();
        }
        if(!s.empty()) {
            pre_smaller[i] = s.back();
        }
        s.push_back(i);
    }

    s.clear();
    for(int i = N - 1; i >= 0; i--) {
        while(!s.empty() && A[s.back()] > A[i]) {
            s.pop_back();
        }
        if(!s.empty()) {
            nxt_smaller[i] = s.back();
        }
        s.push_back(i);
    }

    s.clear();
    for(int i = 0; i < N; i++) {
        while(!s.empty() && A[s.back()] < A[i]) {
            s.pop_back();
        }
        if(!s.empty()) {
            pre_greater[i] = s.back();
        }
        s.push_back(i);
    }

    s.clear();
    for(int i = N - 1; i >= 0; i--) {
        while(!s.empty() && A[s.back()] < A[i]) {
            s.pop_back();
        }
        if(!s.empty()) {
            nxt_greater[i] = s.back();
        }
        s.push_back(i);
    }

    std::vector<int> bad(N, -1);
    for(int i = 0; i < N; i++) {
        int l = pre_greater[i];
        int r = nxt_smaller[i];
        if(l != -1 && r != N) {
            bad[r] = std::max(bad[r], l);
        }
        l = pre_smaller[i];
        r = nxt_greater[i];
        if(l != -1 && r != N) {
            bad[r] = std::max(bad[r], l);
        }

        if(i) {
            bad[i] = std::max(bad[i], bad[i - 1]);
        }
    }
    
    int64_t ans = int64_t(N + 1) * N / 2;
    for(int i = 0; i < N; i++) {
        if(bad[i] != -1) {
            ans -= bad[i] + 1;
        } 
    }
    
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
