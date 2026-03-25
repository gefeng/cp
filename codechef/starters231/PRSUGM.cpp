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

    if(N == 1) {
        std::cout << A[0] << '\n';
        return;
    }

    if(N == 2) {
        std::cout << std::max(A[0], A[1]) << '\n';
        return;
    }

    int lo = 1;
    int hi = N;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        std::vector<int> a(N, 0);
        for(int i = 0; i < N; i++) {
            if(A[i] >= mid) {
                a[i] = 1;
            }
        }

        std::vector<int> dp1(N, 0);
        std::vector<int> dp2(N, 0);
        
        for(int i = 0; i < N; i++) {
            if(i == 0) {
                dp1[i] = a[i] == 1 ? 1 : 0;
            } else if(i == 1) {
                dp1[i] = a[0] == 1 || a[1] == 1 ? 1 : 0;
            } else {
                if(a[i] == 1) {
                    if(dp1[i - 2] || (i - 3 >= 0 && dp1[i - 3])) {
                        dp1[i] = 1;
                    }
                } else {
                    if(a[i - 1] == 1 && i - 3 >= 0 && dp1[i - 3]) {
                        dp1[i] = 1;
                    }
                }
            }
        }

        for(int i = N - 1; i >= 0; i--) {
            if(i == N - 1) {
                dp2[i] = a[i] == 1 ? 1 : 0;
            } else if(i == N - 2) {
                dp2[i] = a[N - 1] == 1 || a[N - 2] == 1 ? 1 : 0;
            } else {
                if(a[i] == 1) {
                    if(dp2[i + 2] || (i + 3 < N && dp2[i + 3])) {
                        dp2[i] = 1;
                    }
                } else {
                    if(a[i + 1] == 1 && i + 3 < N && dp2[i + 3]) {
                        dp2[i] = 1;
                    }
                }
            }
        }

        bool ok = false;
        for(int i = 1; i < N - 1; i++) {
            if(dp1[i - 1] && dp2[i + 1]) {
                ok = true; 
                break;
            }
        }

        if(ok) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
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
