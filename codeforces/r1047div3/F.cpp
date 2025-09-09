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
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int> pre_a(N, -1);
    std::vector<int> pre_b(N, -1);
    std::vector<int> stk;
    for(int i = 0; i < N; i++) {
        while(!stk.empty() && A[stk.back()] < A[i]) {
            stk.pop_back();
        } 
        if(!stk.empty()) {
            pre_a[i] = stk.back();
        }
        stk.push_back(i);
    }

    stk.clear();
    for(int i = 0; i < N; i++) {
        while(!stk.empty() && A[stk.back()] < A[i]) {
            stk.pop_back();
        }
        stk.push_back(i);

        int lo = 0;
        int hi = stk.size() - 1;
        int j = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            if(A[stk[mid]] >= B[i]) {
                j = stk[mid];
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        pre_b[i] = j;
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        ans += static_cast<int64_t>(i + 1) * (N - i);
        if(A[i] == B[i]) {
            continue;
        }
        int l = std::min(pre_a[i], pre_b[i]);
        ans -= static_cast<int64_t>(i - l) * (N - i); 
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
