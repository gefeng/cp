#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int INF = (int)2e9;

void run_case(int T) {
    int N;
    std::cin >> N;

    int n = 2 * N - 1;
    std::vector<int> A(n);
    for(int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    if(N == 1) {
        std::cout << "Case #" << T << ": " << 1 << '\n'; 
        return;
    }

    std::sort(A.begin(), A.end());
    
    int64_t t = 0;
    int64_t ans = INF;
    // if x is minimum
    t = A[0] + A[n - 2];
    int64_t x = t - A.back();
    if(x > 0) {
        bool ok = true;
        for(int i = 1; i < N; i++) {
            if(A[i - 1] + A[n - i - 1] != t) {
                ok = false;
                break;
            }
        } 

        if(ok) {
            ans = std::min(ans, x);
        }
    }

    // if x is maximum
    t = A[1] + A.back();
    x = t - A[0];
    if(x > 0) {
        bool ok = true;
        for(int i = 1; i < N; i++) {
            if(A[i] + A[n - i] != t) {
                ok = false;
                break;
            }
        }

        if(ok) {
            ans = std::min(ans, x);
        }
    }

    // if x is either max or min 
    t = A[0] + A.back();
    int64_t y = 0;
    int cnt = 0;
    for(int l = 1, r = n - 2; l <= r; ) {
        if(l == r) {
            cnt += 1;
            y = A[l];
            break;
        }
        if(A[l] + A[r] == t) {
            l += 1;
            r -= 1;
        } else {
            cnt += 1;
            if(A[l] + A[r] > t) {
                y = A[r--];
            } else {
                y = A[l++]; 
            }
        } 
    }

    if(cnt <= 1) {
        ans = std::min(ans, t - y);         
    }

    ans = ans == INF ? -1 : ans;
    std::cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
