#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N, L, R;
    std::cin >> N >> L >> R;
    L -= 1;
    R -= 1;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int prefix = L;
    int suffix = N - R - 1;

    std::sort(A.begin(), A.begin() + prefix);
    std::sort(A.begin() + prefix, A.begin() + R + 1);
    std::sort(A.begin() + R + 1, A.end());
    
    int64_t sum = 0;
    int64_t ans = INF;
    
    if(prefix) {
        int l = 0;
        int r = R;
        while(l < prefix && r >= L) {
            if(A[l] < A[r]) {
                sum += A[l]; 
            } else {
                break;
            }
            l += 1;
            r -= 1;
        }

        while(r >= L) {
            sum += A[r--];
        }

        ans = std::min(ans, sum);
    }

    if(suffix) {
        int l = R;
        int r = R + 1;
        sum = 0;
        while(l >= L && r < N) {
            if(A[l] > A[r]) {
                sum += A[r];
            } else {
                break;
            }
            l -= 1;
            r += 1;
        }
    
        while(l >= L) {
            sum += A[l--];
        }

        ans = std::min(ans, sum);
    }

    if(prefix == 0 && suffix == 0) {
        for(int x : A) {
            sum += x;
        }
        ans = sum;
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
