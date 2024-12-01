#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = int64_t(3e9);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int> sorted(A);
    std::sort(sorted.begin(), sorted.end());
    int median = sorted[(N - 1) / 2];

    std::vector<int> a; // zero
    std::vector<int> b; // one
    for(int i = 0; i < N; i++) {
        if(B[i] == 0) {
            a.push_back(A[i]);
        } else {
            b.push_back(A[i]);
        }
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    
    int m = b.size();
    std::vector<int64_t> psum(m + 1);
    for(int i = 1; i <= m; i++) {
        psum[i] = psum[i - 1] + b[i - 1];
    }

    int64_t lo = 1;
    int64_t hi = MAX;
    int64_t ans = 0;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        int64_t most = (N - 2) / 2;
        bool ok = false;
        for(int i = 0; i < N; i++) {
            if(A[i] >= mid) {
                ok = true;
                break;
            }
            if(B[i] == 1) {
                int64_t new_m = 0;
                if(A[i] < median) {
                    new_m = N % 2 == 0 ? sorted[(N - 1) / 2 + 1] : median;
                } else {
                    if(N % 2 == 0) {
                        new_m = A[i] == median ? sorted[(N - 1) / 2 + 1] : median; 
                    } else {
                        new_m = sorted[(N - 1) / 2 - 1];
                    }
                }

                if(new_m + A[i] + K >= mid) {
                    ok = true;
                    break;
                }
            }  

            int64_t x = mid - A[i];
            int64_t cnt1 = std::lower_bound(a.begin(), a.end(), x) - a.begin();
            int64_t cnt2 = std::lower_bound(b.begin(), b.end(), x) - b.begin(); 

            if(B[i] == 0 && A[i] < x) {
                cnt1 -= 1; 
            }
            if(B[i] == 1 && A[i] < x) {
                cnt2 -= 1;
            }

            if(cnt1 + cnt2 <= most) {
                ok = true;
                break;
            }

            int64_t d = cnt1 + cnt2 - most;
            if(cnt2 >= d) {
                int j = std::lower_bound(b.begin(), b.end(), x) - b.begin() - 1;
                int k = j + 1 - d; 
                int64_t sum = psum[j + 1] - psum[k];
                if(B[i] == 1 && A[i] < x && A[i] >= b[k]) {
                    sum -= A[i];
                    sum += b[k - 1];
                }

                if(d * x - sum <= K) {
                    ok = true;
                    break;
                }
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
