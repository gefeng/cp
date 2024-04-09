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
    int64_t K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = 0;
    for(int l = 0, r = N - 1, p = 0; l <= r && K; ) {
        if(l == r) {
            ans += A[l] <= K ? 1 : 0;
            break;
        } 

        if(p == 0) {
            if(A[l] <= A[r]) {
                int need = A[l] * 2 - 1;
                if(need <= K) {
                    K -= need;
                    ans += 1;
                    A[r] -= A[l] - 1;
                    A[l] = 0;
                    p = 1;
                    l += 1;
                } else {
                    K = 0;
                }
            } else {
                int need = A[r] * 2;
                if(need <= K) {
                    K -= need;
                    ans += 1;
                    A[l] -= A[r];
                    A[r] = 0;
                    p = 0;
                    r -= 1;
                } else {
                    K = 0;
                }
            }
        } else {
            if(A[l] >= A[r]) {
                int need = A[r] * 2 - 1;
                if(need <= K) {
                    K -= need;
                    ans += 1;
                    A[l] -= A[r] - 1;
                    A[r] = 0;
                    p = 0;
                    r -= 1;
                } else {
                    K = 0;
                }
            } else {
                int need = A[l] * 2;
                if(need <= K) {
                    K -= need;
                    ans += 1;
                    A[r] -= A[l];
                    A[l] = 0;
                    p = 1; 
                    l += 1;
                } else {
                    K = 0;
                }
            }
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
