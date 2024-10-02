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

    int ans = 0;
    int l = 0;
    int r = N - 1;
    int good_l = 0;
    int good_r = N - 1;
    while(l <= r) {
        int len = r - l + 1;
        if(A[l] < len && A[r] < len) {
            good_l = -1;
            good_r = -1;
            break;
        }
        
        if(A[l] >= len && A[r] >= len) {
            l += 1;
            r -= 1;
        } else if(A[l] >= len) {
            l += 1;
            good_l = l;
        } else {
            r -= 1;
            good_r = r;
        }
    }

    for(int i = 0; i < N; i++) {
        int bad_l = i - A[i];
        int bad_r = i + A[i];
        good_l = std::max(good_l, bad_l + 1);
        good_r = std::min(good_r, bad_r - 1);
    }

    ans = (good_l <= good_r && good_l != -1) ? good_r - good_l + 1 : 0;
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
