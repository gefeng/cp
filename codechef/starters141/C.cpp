#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    int max_v = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        max_v = std::max(max_v, A[i]);
    }

    int lo = 1;
    int hi = max_v;
    int x = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        int l = 0;
        int r = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] < mid) {
                l += 1;
            } else {
                r += 1;
            }
        }

        for(int i = 0; i < N; i++) {
            if(A[i] >= mid) {
                continue;
            }

            int j = i;
            while(i < N && A[i] < mid) {
                i += 1;
            }
            l -= i - j - 1;
            i -= 1;
        }

        if(l < r) {
            x = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    std::string ans(N, '0');
    for(int i = 0; i < N; i++) {
        if(A[i] <= x) {
            ans[i] = '1';
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
