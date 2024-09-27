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
    
    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t lo = 1;
    int64_t hi = *std::max_element(A.begin(), A.end());
    int64_t max_v = 0;
    int64_t min_v = 0;
    int64_t ans = 0;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        std::vector<int64_t> a(A);
        for(int i = 0; i < N - 1; i++) {
            a[i + 1] += std::max(int64_t(0), a[i] - mid);
        } 
        
        if(a.back() <= mid) {
            max_v = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    for(int i = 0; i < N - 1; i ++) {
        int64_t d = std::max(int64_t(0), A[i] - max_v);
        A[i] -= d;
        A[i + 1] += d;
    }

    lo = 1;
    hi = max_v;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        std::vector<int64_t> a(A);
        for(int i = N - 1; i > 0; i--) {
            a[i - 1] -= std::max(mid - a[i], int64_t(0));
        } 

        if(a[0] >= mid) {
            min_v = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    for(int i = N - 1; i > 0; i--) {
        int64_t d = std::max(min_v - A[i], int64_t(0));
        A[i] += d; 
        A[i - 1] -= d;
    }

    ans = *std::max_element(A.begin(), A.end()) - *std::min_element(A.begin(), A.end());
    
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
